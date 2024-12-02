
#include "sqlist.h"

void menu(sqlist *lib)
{
    while (1)
    {
        printf("图书管理系统\n");
        printf("0:退出系统\n");
        printf("1:添加图书\n");
        printf("2:删除图书\n");
        printf("3:修改图书\n");
        printf("4:查找图书\n");
        printf("5:重新排序\n");
        printf("6:显示图书\n");
        printf("7:图书数目\n");
        printf("请输入您的选择:\n");

        int select = 6;
        scanf("%d", &select);
        switch (select)
        {
        case 0:
            free(lib);
            exitSystem(lib);
            break;
        case 1:
            list_addElement(lib);
            break;
        case 2:
            list_deleteElement(lib);
            break;
        case 3:
            list_modifyElement(lib);
            break;
        case 4:
            list_findElement(lib);
            break;
        case 5:
            list_sortElement(lib);
            break;
        case 6:
            list_showElement(lib);
            break;
        case 7:
            printf("共有%d本图书\n", list_Length(lib));
            break;
        default:
            printf("输入错误,请重新输入!\n");
            system("clear");
            break;
        }
    }
}

int main()
{
    sqlist *lib = list_create();

    //menu(lib);
    element b;
    strcpy(b.m_name, "insert");
    strcpy(b.m_writer, "Jack");
    b.m_price = 99.99;

    // list_insertElement(lib, 2, b);

    free(lib);

    return 0;
}