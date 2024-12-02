#ifndef __SQLIST_H_
#define __SQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 100
#define STRLEN 10

typedef struct
{
    char m_name[STRLEN];
    char m_writer[STRLEN];
    float m_price;
} element;

typedef struct
{
    element data[N];
    int last;
} sqlist, *psqlist;

sqlist* list_create();
bool list_isEmpty(sqlist *list);
bool list_isFull(sqlist *list);
int list_Length(sqlist *list);
int list_initElement(sqlist *list);
int list_addElement(sqlist *list);
int list_deleteElement(sqlist *list);
int list_modifyElement(sqlist *list);
int list_findElement(sqlist *list);
int list_insertElement(sqlist *list, int index);
void list_sortElement(sqlist *list);
void list_showSingleElement(sqlist *list, int index);
void list_showElement(sqlist *list);
int list_clearElement(sqlist *list);
int saveFile(sqlist *list);
void exitSystem(sqlist *list);

#endif