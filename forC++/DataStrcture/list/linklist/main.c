
#include "linklist.h"

int main()
{
    linklist H = linklist_create();
  
    for (int i = 1; i < 10; i++)
    {
        linklist_tail_insert(H, i);
    }
    linklist_show(H);

    linklist_insert(H, 99, 2);
    linklist_show(H);

    linklist_delete(H, 2);
    linklist_show(H);

    linklist_reverseList(H);
    linklist_show(H);
    linklist_reverseList(H);
    linklist_show(H);

    linklist J = linklist_create();
    for (int i = 1; i < 10; i++)
    {
        linklist_tail_insert(J, i * i);
    }
    linklist_show(J);
    linklist_merge(H, J);
    linklist_show(H);
    linklist_show(J);

    H = linklist_clean(H);
    J = linklist_clean(J);

    return 0;
}