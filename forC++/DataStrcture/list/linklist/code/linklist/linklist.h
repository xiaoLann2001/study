#ifndef _LINKLIST_H__
#define _LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int data_t;

//typedef struct node{} listnode, *linklist
typedef struct node
{
    //data of node
    data_t data;
    //pointer to next node
    struct node *next;
}listnode, *linklist;

/**
 * @brief   create a linklist
 * @return  pointer to new linklist's head
 * */
linklist linklist_create();

/**
 * @brief   get length of linklist
 * @param   head -pointer to linklist's head
 * @return  length of linklist
 * */
int linklist_getLength(linklist head);

/**
 * @brief   get node's address by index of linklist
 * @param   head -pointer to linklist's head
 *          index -location to get address
 * @note    index must be legal
 * */
linklist linklist_getAddressByIndex(linklist head, int index);

/**
 * @brief   insert a node at linklist's tail
 * @param   head -pointer to linklist's head
 *          data -element to insert
 * @return  0 -run successfully
 *          -1 -run failed
 * */
int linklist_tail_insert(linklist head, data_t data);

/**
 * @brief   get the pointer of linklist's tail
 * @param   head -pointer to linklist's head
 * @return  the pointer of linklist's tail
 * */
linklist linklist_pointerOftail(linklist head);

/**
 * @brief   insert a node at linklist's location at will
 * @param   head -pointer to linklist's head
 *          data -data to insert
 *          index -location to insert
 * @return  0 -run successfully
 *          -1 -run failed
 * */
int linklist_insert(linklist head, data_t data, int index);

/**
 * @brief   delete a node in linklist
 * @param   head -pointer to linklist's head
 *          index -location to delete
 * @return  0 -run successfully
 *          -1 -run failed
 * */
int linklist_delete(linklist head, int index);

/**
 * @brief   reverse linklist excecpt headnode
 * */
static linklist linklist_reverse(linklist head);

/**
 * @brief   reverse the linklist
 * @param   head -pointer to linklist's head
 * @return  0 -run successfully
 *          -1 -run failed
 * */
int linklist_reverseList(linklist head);

/**
 * @brief   find the first node in two adjacent nodes that sum of they data is
 *          largest 
 * @param   head -pointer to linklist's head
 * @return  pointer of satisfactory first node
 * */
linklist linklist_adjmax(linklist head);

/**
 * @brief   copy a linklist to new space
 * @param   head -pointer to linklist's head
 * @return  pointer of new linklist's head
 * */
linklist linklist_copy(linklist head);

/**
 * @brief   merge two ordered linklist to A
 * @param   headA -pointer to pointer of linklist A's head
 * @param   headB -pointer to linklist B's head
 * @return  0 -run successfully
 *          -1 -run failed
 * */
int linklist_merge(linklist headA, linklist headB);

/**
 * @brief   merge two ordered linklist to A
 * @param   pheadA -pointer to pointer of linklist A's head
 * @param   headB -pointer to linklist B's head
 * @return  0 -run successfully
 *          -1 -run failed
 * */
int linklist_myMerge(linklist* pheadA, linklist headB);

/**
 * @brief   clean the memory of linklist
 * @param   head -pointer to linklist's head
 * @return  empty pointer
 * */
linklist linklist_clean(linklist head);

/**
 * @brief print info of linklist
 * @param   head -pointer to linklist's head
 * @return  0 -run successfully
 *          -1 -run failed
 * */
int linklist_show(linklist head);

#endif
