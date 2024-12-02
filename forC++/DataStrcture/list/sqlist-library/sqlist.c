
#include "sqlist.h"

#define FILENAME "database.txt"

sqlist* list_create()
{
    sqlist *list = (sqlist *)malloc(sizeof(sqlist));
    if (list == NULL){
        printf("list malloc failed\n");
        exit(0);
    }
    list_clearElement(list);
    list_initElement(list);
    return list;
}

bool list_isEmpty(sqlist *list)
{
    if(list->last == -1)
    {
        return true;
    }
    return false;
}

bool list_isFull(sqlist *list)
{
    if(list->last == N - 1)
    {
        return true;
    }
    return false;
}

int list_Length(sqlist *list)
{
    return list->last + 1;
}

int list_initElement(sqlist *list)
{
    FILE *pf = fopen(FILENAME, "r");
    if (pf == NULL)
    {
        printf("init fail");
        return -1;
    }
    else if (fgetc(pf) == EOF)
    {
        printf("there is not element\n");
        fclose(pf);
        return -1;
    }
    rewind(pf);

    list->last = 0;
    while (fscanf(pf, "%s %s %f", list->data[list->last].m_name,
                  list->data[list->last].m_writer,
                  &list->data[list->last].m_price) == 3)
    {
        list->last++;
        if (list->last >= N){
            break;
        }
    }
    list->last--;

    fclose(pf);
    pf = NULL;
    return 0;
}

int list_addElement(sqlist *list)
{
    if (list_isFull(list))
    {
        printf("警告: 图书已满\n");
        return -1;
    }
    else
    {
        char name[STRLEN];
        char writer[STRLEN];
        float price;

        printf("添加新的图书:\n");

        printf("book: ");
        scanf("%s", name);
        printf("writer: ");
        scanf("%s", writer);
        printf("price: ");
        scanf("%f", &price);

        list->last++;
        strcpy(list->data[list->last].m_name, name);
        strcpy(list->data[list->last].m_writer, writer);
        list->data[list->last].m_price = price;

        saveFile(list);
        printf("添加成功\n");
        return 0;
    }
}

int list_deleteElement(sqlist *list)
{
    if (list_isEmpty(list))
    {
        printf("警告: 没有图书");
        return -1;
    }
    else
    {
        list_showElement(list);
        printf("选择要删除图书的索引：");

        int index;
        scanf("%d", &index);
        for (int i = index; i < list->last; i++)
        {
            list->data[i] = list->data[i + 1];
        }
        list->last--;

        saveFile(list);
        printf("删除成功");
        return 0;
    }
}

int list_modifyElement(sqlist *list)
{
    if (list_isEmpty(list))
    {
        printf("警告: 没有图书");
        return -1;
    }
    else
    {
        char name[STRLEN];
        char writer[STRLEN];
        float price;
        int index;

        list_showElement(list);
        printf("选择要修改图书的索引：");
        scanf("%d", &index);

        printf("book: ");
        scanf("%s", name);
        printf("writer: ");
        scanf("%s", writer);
        printf("price: ");
        scanf("%f", &price);

        strcpy(list->data[index].m_name, name);
        strcpy(list->data[index].m_writer, writer);
        list->data[index].m_price = price;

        saveFile(list);
        printf("修改成功");
        return 0;
    }
}

int list_findElement(sqlist *list)
{
    if (list_isEmpty(list))
    {
        printf("警告: 没有图书");
        return -1;
    }
    else
    {
        int select;
        char ch[STRLEN];
        int flag_havefound = 0;

        printf("按 1.书名查找;  2.按作者名查找; ");
        scanf("%d", &select);

        switch (select)
        {
        case 1:
            printf("输入书名:");
            scanf("%s", ch);

            for (int i = 0; i < list->last; i++)
            {
                if (0 == strcmp(ch, list->data[i].m_name))
                {
                    list_showSingleElement(list, i);
                    flag_havefound = 1;
                }
            }
            break;
        case 2:
            printf("输入作者名:");
            scanf("%s", ch);

            for (int i = 0; i < list->last; i++)
            {
                if (0 == strcmp(ch, list->data[i].m_writer))
                {
                    list_showSingleElement(list, i);
                    flag_havefound = 1;
                }
            }
            break;
        default:
            printf("输入错误\n");
            return -1;
            break;
        }
        if (flag_havefound)
        {
            printf("以上图书符合条件\n");
            return 0;
        }
        else
        {
            printf("没有符合条件的图书\n");
            return -1;
        }
    }
}

int list_insertElement(sqlist *list, int index)
{
    if(list_isFull(list) || (index < 0 || index > list->last + 1))
    {
        return -1;
    }else{
        for (int i = list->last; i >= index; i--)
        {
            strcpy(list->data[i + 1].m_name, list->data[i].m_name);
            strcpy(list->data[i + 1].m_writer, list->data[i].m_writer);
            list->data[i + 1].m_price = list->data[i].m_price;
        } 

        char name[STRLEN];
        char writer[STRLEN];
        float price;

        printf("插入新的图书:\n");

        printf("book: ");
        scanf("%s", name);
        printf("writer: ");
        scanf("%s", writer);
        printf("price: ");
        scanf("%f", &price);

        strcpy(list->data[index].m_name, name);
        strcpy(list->data[index].m_writer, writer);
        list->data[index].m_price = price;
        list->last++;

        saveFile(list);
        return 0;
    }
}

void list_sortElement(sqlist *list)
{
    if (list_isEmpty(list))
    {
        printf("警告: 没有图书");
        return;
    }else{
        int select_member;
        int select_riseOrDown;

        printf("按 1.书名排序;  2.按作者名排序; 3.按价格排序:");
        scanf("%d", &select_member);
        if (select_member != 1 && select_member != 2 && select_member != 3){
            printf("输入错误\n");
            return;
        }
        printf("1.升序排序;  2.降序排序:");
        scanf("%d", &select_riseOrDown);
        if (select_riseOrDown != 1 && select_riseOrDown != 2){
            printf("输入错误\n");
            return;
        }

        for (int i = 0; i <= list->last; i++){
            int minIndexOrMaxIndex = i;
            for (int j = i + 1; j <= list->last; j++){
                switch (select_member){
                // case 1:
                //     if (select_riseOrDown == 1){
                //         if (strcmp(list->data[j].m_name, list->data[minIndexOrMaxIndex].m_name) == -1){
                //             minIndexOrMaxIndex = j;
                //         }
                //     }else{
                //         if (strcmp(list->data[j].m_name, list->data[minIndexOrMaxIndex].m_name) == 1){
                //             minIndexOrMaxIndex = j;
                //         }
                //     }
                //     break;
                case 1:
                    if (select_riseOrDown == 1) {
                        if (strcmp(list->data[j].m_name, list->data[minIndexOrMaxIndex].m_name) < 0) {
                            minIndexOrMaxIndex = j;
                        }
                    } else {
                        if (strcmp(list->data[j].m_name, list->data[minIndexOrMaxIndex].m_name) > 0) {
                            minIndexOrMaxIndex = j;
                        }
                    }
                    break;
                case 2:
                    if (select_riseOrDown == 1){
                        if (strcmp(list->data[j].m_writer, list->data[minIndexOrMaxIndex].m_writer) < 0){
                            minIndexOrMaxIndex = j;
                        }
                    }else{
                        if (strcmp(list->data[j].m_writer, list->data[minIndexOrMaxIndex].m_writer) > 0){
                            minIndexOrMaxIndex = j;
                        }
                    }
                    break;
                case 3:
                    if (select_riseOrDown == 1){
                        if (list->data[j].m_price < list->data[minIndexOrMaxIndex].m_price){
                            minIndexOrMaxIndex = j;
                        } 
                    }else{
                        if (list->data[j].m_price > list->data[minIndexOrMaxIndex].m_price){
                            minIndexOrMaxIndex = j;
                        }
                    }
                    break;
                default:
                    break;
                }
            }

            if (minIndexOrMaxIndex != i){
                element temp;
                strcpy(temp.m_name, list->data[i].m_name);
                strcpy(temp.m_writer, list->data[i].m_writer);
                temp.m_price = list->data[i].m_price;
                strcpy(list->data[i].m_name, list->data[minIndexOrMaxIndex].m_name);
                strcpy(list->data[i].m_writer, list->data[minIndexOrMaxIndex].m_writer);
                list->data[i].m_price = list->data[minIndexOrMaxIndex].m_price;
                strcpy(list->data[minIndexOrMaxIndex].m_name, temp.m_name);
                strcpy(list->data[minIndexOrMaxIndex].m_writer, temp.m_writer);
                list->data[minIndexOrMaxIndex].m_price = temp.m_price;
            } 
        } 
        saveFile(list);
        list_showElement(list);
    }
}

int list_clearElement(sqlist *list)
{
    if (list == NULL)
    {
        return -1;
    }
    // list->last = -1;     //顺序不要反了，先置零再设为空表
    memset(list, 0, sizeof(sqlist));
    list->last = -1;
    return 0;
}

int saveFile(sqlist *list)
{
    FILE *pf = fopen(FILENAME, "w");
    if (pf == NULL)
    {
        printf("save fail\n");
        return -1;
    }
    for (int i = 0; i <= list->last; i++)
    {
        char temp[100];
        sprintf(temp, "%s %s %.2f\n",
                list->data[i].m_name, list->data[i].m_writer, list->data[i].m_price);
        fputs(temp, pf);
    }
    fclose(pf);
    pf = NULL;
    return 0;
}

void list_showSingleElement(sqlist *list, int index)
{
    printf("%d\tbook: %s\twriter: %s\tprice: %.2f\n",
           index, list->data[index].m_name, list->data[index].m_writer, list->data[index].m_price);
}

void list_showElement(sqlist *list)
{
    if (list_isEmpty(list))
    {
        printf("list is empty\n");
        return;
    }else{
        printf("-----show-----\n");
        for (int i = 0; i <= list->last; i++)
        {
            list_showSingleElement(list, i);
        }
        printf("-----end-----\n");
    } 
}

void exitSystem(sqlist *list)
{
    printf("good bye\n");
    exit(0);
}
