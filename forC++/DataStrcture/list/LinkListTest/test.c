#include <stdio.h>
#include <cstdlib>

typedef int ElemType; 		// 数据类型可以自定义

typedef struct ListNode {
    ElemType data;           	// 数据域
    struct ListNode *next;   	// 指针域，指向下一个节点
} ListNode;

void printList(ListNode* pHead) {
    ListNode* p = pHead;
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

ListNode* createNode(ElemType value) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (!node) {
        printf("内存分配失败！\n");
        return NULL;
    }
    node->data = value;
    node->next = NULL;
    return node;
}

void insertHead(ListNode** pHead, ElemType value) {
    ListNode* node = createNode(value);
    node->next = *pHead;
    *pHead = node;
}

void insertTail(ListNode** pHead, ElemType value) {
    ListNode* node = createNode(value);
    
    if (NULL == *pHead) {
        *pHead = node;
    } else {
        ListNode* p = *pHead;
        while (p->next) 
            p = p->next;
        p->next = node;     // 此时p指向最后一个节点
    }
}

void deleteNodeByValue(ListNode **pHead, ElemType value) {
    if (*pHead == NULL) {
        printf("Error: delete empty list!\n");
        return;
    }

    ListNode *temp = *pHead;
    ListNode** prev = pHead;

    // 遍历链表找目标值
    while (temp != NULL && temp->data != value) {
        prev = &(temp->next);   // 记录前驱节点后向指针 next 的地址
        temp = temp->next;
    }

    if (temp != NULL) {
        *prev = temp->next; // 修改前驱节点后向指针 next，指向下一个节点
        free(temp);
        return;
    }
}

// void deleteNodeByValue(ListNode** pHead, ElemType value) {
//     // 链表为空
//     if (*pHead == NULL) {
//         printf("Error: delete empty list!\n");
//         return;
//     }

//     ListNode* temp = *pHead;
//     ListNode* prev = NULL;

//     // 处理头节点
//     if (temp->data == value) {
//         *pHead = temp->next;    // 头指针指向下一个节点
//         free(temp);
//         return;
//     }

//     // 遍历链表找目标值
//     while (temp != NULL && temp->data != value) {
//         prev = temp;
//         temp = temp->next;
//     }

//     // 找到目标值
//     if (temp) {
//         prev->next = temp->next;    // 待删除节点的上一个节点指向待删除节点的下一个节点
//         free(temp);
//         return;
//     }
// }

void deleteNodeByPos(ListNode** pHead, int pos) {
    if (*pHead == NULL) {
        printf("Error: empty list!\n");
        return;
    }

    if (pos < 0) {
        printf("Error: invalid position!\n");
        return;
    }

    ListNode* temp = *pHead;
    ListNode** prev = pHead;
    int index = 0;

    // 遍历到第 pos 个节点
    while (temp != NULL && index < pos) {
        prev = &(temp->next);   // 前驱的 next 指针地址
        temp = temp->next;
        index++;
    }

    if (temp != NULL) {
        *prev = temp->next;  // 删除当前节点
        free(temp);
    } else {
        printf("Error: position %d out of range!\n", pos);
    }
}

void deleteNodeDirect(ListNode *node) {
    if (node == NULL || node->next == NULL) {
        printf("Error: node is NULL or cannot delete tail node this way!\n");
        return;
    }

    ListNode *next = node->next;
    node->data = next->data;        // 复制下一个节点的数据
    node->next = next->next;        // 跳过下一个节点
    free(next);                     // 释放下一个节点
}

int main() {
    ListNode* pHead = createNode(5);
    pHead->next = createNode(1);
    pHead->next->next = createNode(3);

	printList(pHead);
	deleteNodeDirect(pHead->next);
    printList(pHead);

    return 0;
}