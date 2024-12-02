#include "linklist.h"

linklist linklist_create()
{
    //1.request memory
    linklist list = (linklist)malloc(sizeof(listnode));
    
    //2.check null
    if(NULL == list){
        printf("malloc failed\n");
        return NULL;
    } 

    //3.value
    list->data = 0;
    list->next = NULL;

    //4.return pointer of new linklist
    return list;
}

int linklist_getLength(linklist head)
{
    //1.check null
    if(NULL == head)
    {
        printf("error linklist\n");
        return -1;
    }

    //2.get length
    linklist p = head;
    int count = 0;
    while (NULL != p->next)
    {
        p = p->next;
        count++;
    }
    
    //3.return
    return count;
}

linklist linklist_getAddressByIndex(linklist head, int index)
{
    //1.check null
    if(NULL == head)
    {
        printf("error linklist\n");
        return head;
    }

    //2.check index
    if((index < -1) || (index > linklist_getLength(head)))
    {
        printf("error index\n");
        return NULL;
    }
    
    //3.get address
    linklist p = head;
    int i = -1;
    while ((NULL != p->next) && (i < index))
    {
        p = p->next;
        i++;
    }
    return p;
}

int linklist_tail_insert(linklist head, data_t data)
{
    //1.check null
    if(NULL == head)
    {
        printf("error linklist\n");
        return -1;
    }

    //2.create new listnode
    linklist tail = linklist_create();

    //3.value
    tail->data = data;
    tail->next = NULL;

    //4.link tail to linklist
    linklist p = linklist_pointerOftail(head);
    p->next = tail;

    return 0;
}

linklist linklist_pointerOftail(linklist head)
{
    //1.check null
    if(NULL == head)
    {
        printf("error linklist\n");
        return head;
    }

    //2.get pointer of tail
    linklist p = head;
    while (NULL != p->next)
    {
        p = p->next;
    }

    //3.return
    return p;
}

int linklist_insert(linklist head, data_t data, int index)
{
    //1.check null
    if(NULL == head)
    {
        printf("error linklist\n");
        return -1;
    }

    //2.create new listnode
    linklist node = linklist_create();

    //3.value
    node->data = data;

    //4.get pointer of (index-1)
    linklist p = linklist_getAddressByIndex(head, index - 1);
    if (NULL == p)
    {
        printf("error address\n");
        return -1;
    }

    //5.link node to linklist
    node->next = p->next;
    p->next = node;

    return 0;
}

int linklist_delete(linklist head, int index)
{
    //1.check null
    if(NULL == head)
    {
        printf("error linklist\n");
        return -1;
    }

    //2.get pointer of (index-1)
    linklist p = linklist_getAddressByIndex(head, index - 1);
    if (NULL == p)
    {
        printf("error address\n");
        return -1;
    }

    //3.delete
    // p->next = p->next->next;
    // free(p->next);   //can't free next node
    //note  -???

    linklist temp = p->next;
    p->next = temp->next;
    free(temp);
    temp->next = NULL;

    return 0;
}

static linklist linklist_reverse(linklist head) 
{
    // Base case: if head is NULL or there's only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Recursively reverse the sublist starting from the next node
    linklist reversed_list = linklist_reverse(head->next);

    // Reverse the pointers
    head->next->next = head;
    head->next = NULL;

    // Return the new head of the reversed list
    return reversed_list;

    // linklist prev = NULL;
    // linklist current = head;
    // linklist next = NULL;

    // while (current != NULL) {
    //     next = current->next; // save next node
    //     current->next = prev; // reverse pointer
    //     prev = current;       // move previous node
    //     current = next;       // move current node
    // }

    // return prev; // prev point new head now
}

int linklist_reverseList(linklist head) 
{
    //1.Base case: if head is NULL or there's only one node
    if (head == NULL) {
        printf("error linklist\n");
        return -1;
    }

    if (head->next == NULL || head->next->next == NULL) {
        return 0;
    }

    //2.1.recursion or interation(head is fixed)
    // head->next = linklist_reverse(head->next);
    // return 0;  

    //2.2.headinsert
    linklist p; //(p)save next node
    linklist q; //(q)save current node will be inserted

    q = head->next;
    p = q->next;
    q->next = NULL;

    while (NULL != p)
    {
        q = p;
        p = p->next;
        q->next = head->next;
        head->next = q;
    }
    
    return 0;
}

linklist linklist_adjmax(linklist head)
{
    //1.check null
    if(NULL == head)
    {
        printf("error linklist\n");
        return NULL;
    }

    //2.check valid
    if(linklist_getLength(head) <= 2)
    {
        return head;
    }
    
    //3.find pointer of max sum
    linklist p;
    linklist max;
    int sum;

    p = head->next;
    max = p;

    while (NULL != p->next)
    {
        sum = p->data + p->next->data;
        if((max->data + max->next->data) < sum)
        {
            max = p;
        }
        p = p->next;
    }
    
    return max;
}

linklist linklist_copy(linklist head)
{
    //1.check null
    if(NULL == head)
    {
        printf("error linklist\n");
        return NULL;
    }

    //2.copy
    linklist list = linklist_create();
    linklist p = head->next;

    while (NULL != p)
    {
        linklist_tail_insert(list, p->data);
        p = p->next;
    }
    
    //3.return head of new linklist
    return list;
}

int linklist_merge(linklist headA, linklist headB)
{
    //1.check null
    if(NULL == headA || NULL == headB)
    {
        printf("error linklist\n");
        return -1;
    }

    // //2.check empty
    // if (NULL == headA->next && NULL == headB->next)
    // {
    //     return 0;
    // } 

    //3.merge lists
    linklist p; //save new head of least linklistA
    linklist q; //save new head of least linklistB
    linklist r; //save tail of linklistA

    p = headA->next;
    q = headB->next;
    r = headA;
    headA->next = NULL; //set linklistA empty
    headB->next = NULL; //set linklistB empty

    // while ((NULL != p) && (NULL != q))
    while (p && q)
    {
        //tail insert the smaller one in (p->data) and (q->data)
        if (p->data < q->data)
        {
            // linklist temp = p;
            // p = p->next;
            // temp->next = NULL;
            // r->next = temp;
            r->next = p;
            p = p->next;
            r = r->next;
            r->next = NULL;
        }else{
            // linklist temp = q;
            // q = q->next;
            // temp->next = NULL;
            // r->next = temp;
            r->next = q;
            q = q->next;
            r = r->next;
            r->next = NULL;
        }
    } 

    //tail left part of (q) 
    if (NULL == p)
    {
        r->next = q;
    }else {//tail left part of (p) 
        r->next = p;
    }
    return 0;
}

int linklist_myMerge(linklist* pheadA, linklist headB)
{
    //1.check null
    if(NULL == (*pheadA) || NULL == headB)
    {
        printf("error linklist\n");
        return -1;
    }

    //2.check empty
    if(NULL == (*pheadA)->next)
    {
        linklist p = (*pheadA);
        (*pheadA) = linklist_copy(headB);
        free(p);
        return 0;
    }
    if(NULL == headB->next)
    {
        return 0;
    }

    //3.merge two linklist
    linklist p; //save next node in B
    linklist q; //save current node in B
    linklist r; //save previous node in A
    int flag_inserted = 0;  //0-have not inserted 1-have inserted

    p = headB->next;

    while (NULL != p)
    {
        q = p;
        p = p->next;
        flag_inserted = 0;

        r = (*pheadA)->next;

        //when node in B will be insert to next of headA
        if (q->data <= (*pheadA)->next->data)
        {
            //insert
            flag_inserted = 1;

            //link (*q) to listA
            q->next = (*pheadA)->next;
            (*pheadA)->next = q;

            //link headB to listB(p)
            headB->next = p;
        }
        //when node in B will be insert to other nodes
        while (NULL != r->next)
        {
            if((0 == flag_inserted) && 
                (q->data > r->data) && (q->data <= r->next->data))
            {
                //insert
                flag_inserted = 1;
                
                //link (*q) to listA
                q->next = r->next;
                r->next = q;

                //link headB to listB(p)
                headB->next = p;
            }
            r = r->next;
        } 
        //when (r->next) equal to NULL, compare (r->data) with (q->data)
        if ((0 == flag_inserted) && (q->data > r->data))
        {
            //insert
            flag_inserted = 1;
            
            //link (*q) to listA
            q->next = r->next;
            r->next = q;

            //link headB to listB(p)
            headB->next = p;
        }
    }

    return 0;
}

linklist linklist_clean(linklist head)
{
    //1.check null
    if(NULL == head)
    {
        printf("error linklist\n");
        return NULL;
    }

    //2.for each listnode
    linklist p = head;
    linklist p1;
    while (NULL != p)
    {
        p1 = p;
        p = p->next;
        free(p1);  
    }

    //3.return
    return NULL;
}

int linklist_show(linklist head)
{
    //1.check null
    if(NULL == head)
    {
        printf("error linklist\n");
        return -1;
    }

    //2.check empty
    if(NULL == head->next)
    {
        printf("linklist is empty\n");
        return 0;
    }

    //3.for each listnode
    linklist p = head->next;
    int i = 0;
    printf("(");
    while (NULL != p)
    {
        printf("%d, ", p->data);
        p = p->next;
        i++;
    }
    printf(")\n");

    p = head;
    i = -1;
    while (NULL != p)
    {
        printf("%d\t| %d\t| %p\n", i, p->data, p->next);
        p = p->next;
        i++;
    }

    //4.return
    return 0;
}
