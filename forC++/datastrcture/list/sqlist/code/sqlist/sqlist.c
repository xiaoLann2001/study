#include "sqlist.h"

sqlink list_create()
{
    //request memory
    sqlink list = (sqlink)malloc(sizeof(sqlist));
    if (NULL == list)
    {
        return NULL;
    }
    //set memory as zero & empty list
    memset(list, 0, sizeof(sqlist));
    list->last = -1;
    return list;
}

int list_clear(sqlink list)
{
    if (-1 == list->last)
    {
        return -1;
    }
    //set memory as zero & empty list
    memset(list, 0, sizeof(sqlist));
    list->last = -1;
    return 0;
}

bool list_isEmpty(sqlink list)
{
    if (-1 == list->last)
    {
        return true;
    }
    return false;
}

bool list_isFull(sqlink list)
{
    if (N - 1 == list->last)
    {
        return true;
    }
    return false;
}

int list_length(sqlink list)
{
    return list->last + 1;
}

int list_insert(sqlink list, int index, data_t data)
{
    //index is illegal 
    if (list_isFull(list) || (index < 0 || index > list->last + 1))
    {
        return -1;
    }
    //move the index element and its right elements
    for (int i = list->last; i >= index; i--)
    {
        //from left to right
        MOVE(list->data[i + 1], list->data[i]);
    }
    //insert new element in index
    MOVE(list->data[index], data);
    list->last++;
    return 0;
}

int list_delete(sqlink list, int index)
{
    //if list is empty | index is illegal 
    if (-1 == list->last || (index < 0 || index > list->last))
    {
        return -1;
    }
    //move the index's right elements to left
    for (int i = index; i < list->last; i++)
    {
        //from right to left
        MOVE(list->data[i], list->data[i + 1]);
    }
    list->last--;
    return 0;
}

int list_modify(sqlink list, int index, data_t data)
{
    //if list is empty | index is invaild
    if (-1 == list->last || (index < 0 || index > list->last))
    {
        return -1;
    }
    //modify index element
    MOVE(list->data[index], data);
    return 0;
}

int list_find(sqlink list, data_t data)
{
    if (-1 == list->last)
    {
        return -1;
    }
    //find foreach
    for (int i = 0; i <= list->last; i++)
    {
        //compare
        if(0 == COMP(list->data[i], data))
            return i;
    }
    return -1;
}

void list_show(sqlink list)
{
    if (-1 == list->last)
    {
        printf("list is empty.\n");
        return;
    }
    for (int i = 0; i <= list->last; i++)
    {
        //print all elements
        PRINT(i);
    }
}

int list_sort(sqlink list, int order)
{
    if (-1 == list->last)
    {
        return -1;
    }
    if (0 == list->last)
    {
        return 0;
    }
    //selection sort algorithm
    int minOrMax;
    for (int i = 0; i < list->last; i++)
    {
        minOrMax = i;
        for (int j = i + 1; j <= list->last; j++)
        {
            if (order > 0)
            {
                if (COMP(list->data[j], list->data[minOrMax]) < 0)
                {
                    minOrMax = j;
                }
            }
            else
            {
                if (COMP(list->data[j], list->data[minOrMax]) > 0)
                {
                    minOrMax = j;
                }
            }
        }
        if (minOrMax != i)
        {
            data_t temp;
            MOVE(temp, list->data[i]);
            MOVE(list->data[i], list->data[minOrMax]);
            MOVE(list->data[minOrMax], temp);
        }
    } 
    return 0;
}

sqlink list_dedup(sqlink list)
{
    //require new memory
    sqlink list_dedup = list_create();
    //if sqlist is empty
    if (-1 == list->last)
    {
        return list_dedup;
    }
    //deduplicate list
    COPY(list_dedup, list);
    for (int i = 0; i <= list_dedup->last; i++)
    {
        for (int j = i + 1; j <= list_dedup->last; j++)
        {
            if (0 == COMP(list_dedup->data[j], list_dedup->data[i]))
            {
                list_delete(list_dedup, j);
                j--;
            }   
        }
    }
    return list_dedup;
}

sqlink list_merge(sqlink list_a, sqlink list_b)
{
    //require new memory
    sqlink list_merge = list_create();
    //if sqlist is empty | sqlist is full
    if (-1 == list_a->last && -1 == list_b->last)
    {
        return list_merge;
    }
    else if (list_a->last + list_b->last > N - 2)
    {
        return list_merge;
    }
    else if (-1 == list_a->last)
    {
        COPY(list_merge, list_b);
        return list_merge;
    }
    else if (-1 == list_b->last)
    {
        COPY(list_merge, list_a);
        return list_merge;
    }
    //merge two sqlists
    COPY(list_merge, list_a);
    for (int i = 0; i <= list_b->last; i++)
    {
        list_insert(list_merge, list_merge->last + 1, list_b->data[i]);
    }
    return list_merge;
}

sqlink list_cross(sqlink list_a, sqlink list_b)
{
    //require new memory
    sqlink list_cross = list_create();
    //if sqlist is empty
    if (-1 == list_a->last || -1 == list_b->last)
    {
        return list_cross;
    }
    //deduplicate lists
    list_a = list_dedup(list_a);
    list_b = list_dedup(list_b);
    //cross two sqlists
    for (int i = 0; i <= list_b->last; i++)
    {
        for (int j = 0; j <= list_a->last; j++)
        {
            //if list_a has list_b's element, they are cross's elements
            if (0 == COMP(list_a->data[j], list_b->data[i]))
            {
                list_insert(list_cross, list_cross->last + 1, list_b->data[i]);
                break;
            }
        }
    }
    return list_cross;
}

sqlink list_union(sqlink list_a, sqlink list_b)
{
    //require new memory
    sqlink list_union = list_create();
    //if sqlist is empty | union is full
    if (-1 == list_a->last && -1 == list_b->last)
    {
        return list_union;
    }
    else if (-1 == list_a->last)
    {
        COPY(list_union, list_b);
        return list_union;
    }
    else if (-1 == list_b->last)
    {
        COPY(list_union, list_a);
        return list_union;
    }
    //deduplicate lists
    list_a = list_dedup(list_a);
    list_b = list_dedup(list_b);
    //union two sqlists
    COPY(list_union, list_a);
    for (int i = 0; i <= list_b->last; i++)
    {
        int flagCross = 0;
        for (int j = 0; j <= list_a->last; j++)
        {
            //if list_a has list_b's element, they are cross's elements
            if (0 == COMP(list_a->data[j], list_b->data[i]))
            {
                flagCross = 1;
                break;
            }
        }
        //list_b[i] is not belong to list_a
        if (0 == flagCross)
        {
            list_insert(list_union, list_union->last + 1, list_b->data[i]);
        }
        if (list_union->last >= N - 1)
        {
            return list_union;
        }
    }
    return list_union;
}

