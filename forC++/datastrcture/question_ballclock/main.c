// 球钟问题

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkqueue.h"
#include "sqstack.h"

bool queue_isOrdered(linkqueue * queue);

int main()
{
    // 创建包含27个球的队列
    linkqueue *ballQueue = linkqueue_create();
    if (NULL == ballQueue)
    {
        exit(-1);
    }

    for (int i = 1; i <= 27; i++)
    {
        linkqueue_enqueue(ballQueue, i);
    }
    linkqueue_show(ballQueue);

    // 创建三个球钟栈
    sqstack *hourStack = sqstack_create(11);
    sqstack *fminuStack = sqstack_create(11);
    sqstack *minuStack = sqstack_create(4);
    if (NULL == hourStack ||
        NULL == fminuStack||
        NULL == minuStack)
    {
        exit(-1);
    }

    int turn = 0;   // 记录轮次

    /// 运行
    while (1)
    {
        // 每过一分钟，队首弹出一个球
        data_t ball = linkqueue_dequeue(ballQueue);
        // 若一分钟栈未满，队首球入一分钟栈
        if (sqstack_isFull(minuStack))
        {
            // 弹出所有四个一分钟球入队尾
            for (int i = 0; i < 4; i++)
            {
                linkqueue_enqueue(ballQueue, sqstack_pop(minuStack));
            }

            // 一分钟栈溢出的球入五分钟栈
            if (sqstack_isFull(fminuStack))
            {
                // 弹出所有十一个五分钟球入队尾
                for (int i = 0; i < 11; i++)
                {
                    linkqueue_enqueue(ballQueue, sqstack_pop(fminuStack));
                }

                // 五分钟栈溢出的球入一小时栈
                if (sqstack_isFull(hourStack))
                {
                    // 弹出所有十一个一小时球入队尾
                    for (int i = 0; i < 11; i++)
                    {
                        linkqueue_enqueue(ballQueue, sqstack_pop(hourStack));
                    }

                    // 一小时栈溢出的球入队尾
                    linkqueue_enqueue(ballQueue, ball);

                    linkqueue_show(ballQueue);
                    // 一轮结束，判断顺序是否正确
                    turn++;
                    if (queue_isOrdered(ballQueue))
                    {
                        printf("need %d turn\n", turn);
                        exit(0);
                    }
                }
                else
                {
                    sqstack_push(hourStack, ball);
                }  
            }
            else
            {
                sqstack_push(fminuStack, ball);
            } 
        }
        else
        {
            sqstack_push(minuStack, ball);
        }

        // printf("current time: %d:%02d\n", 
        //                         hourStack->top + 1,
        //                         5 * (fminuStack->top + 1) + minuStack->top + 1);
        // sqstack_show(hourStack);
        // sqstack_show(fminuStack);
        // sqstack_show(minuStack);
        // linkqueue_show(ballQueue);
    }
}

bool queue_isOrdered(linkqueue * queue)
{
    linklist p = queue->front->next;

    while (NULL != p->next)
    {
        // printf("%p, %d\n", p, p->data);
        if (p->data > p->next->data)
        {
            return false;
        }
        p = p->next;
    }
    return true;
}
