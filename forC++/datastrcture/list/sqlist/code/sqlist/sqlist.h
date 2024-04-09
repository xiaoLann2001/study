
#ifndef __SQLIST_H_
#define __SQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 20
#define MOVE(d, s) ((d) = (s))
#define COMP(a, b) ((a) - (b))
#define COPY(d, s) do { \
  d->last = s->last; \
  for (int i = 0; i <= d->last; i++) \
  { \
    MOVE(d->data[i], s->data[i]); \
  } \
} while (0);
#define PRINT(i) (printf("%d:\t%d\n", (i), list->data[(i)]))

typedef int data_t;
typedef struct{
    data_t data[N];
    int last;
} sqlist, *sqlink;

/**
  * @brief  create a sqlist
  * @return pointer to new sqlist
  **/
sqlink list_create();

/**
  * @brief  -clear sqlist
  * @param  list -pointer to sqlist
  * @return NULL -list create failed, other -pointer to new sqlist
  **/
int list_clear(sqlink list);

/**
  * @brief  -Is sqlist empty
  * @param  list -pointer to sqlist
  * @return true -empty, false -not empty
  **/
bool list_isEmpty(sqlink list);

/**
  * @brief  -Is sqlist full
  * @param  list -pointer to sqlist
  * @return true -full false -not full
  **/
bool list_isFull(sqlink list);

/**
  * @brief  -length of sqlist
  * @param  list -pointer to sqlist
  * @return 0 -empty, >0 -length
  **/
int list_length(sqlink list);

/**
  * @brief  -insert data at specified index in sqlist
  * @param  list -pointer to sqlist
  * @param  index -position to insert data
  * @param  data -data to be inserted
  * @return 0 -success, -1 -failure (e.g., invalid index)
  **/
int list_insert(sqlink list, int index, data_t data);

/**
  * @brief  -delete data at specified index in sqlist
  * @param  list -pointer to sqlist
  * @param  index -position to delete data
  * @return 0 -success, -1 -failure (e.g., invalid index)
  **/
int list_delete(sqlink list, int index);

/**
  * @brief  -modify data at specified index in sqlist
  * @param  list -pointer to sqlist
  * @param  index -position to modify data
  * @param  data -new data to replace existing one
  * @return 0 -success, -1 -failure (e.g., invalid index)
  **/
int list_modify(sqlink list, int index, data_t data);

/**
  * @brief  -find the first occurrence of specified data in sqlist
  * @param  list -pointer to sqlist
  * @param  data -data to search for
  * @return index of the first occurrence, -1 if not found
  **/
int list_find(sqlink list, data_t data);

/**
  * @brief  -display the elements of sqlist
  * @param  list -pointer to sqlist
  * @return void
  **/
void list_show(sqlink list);

/**
  * @brief  -sort the elements of sqlist in ascending order
  * @param  list -pointer to sqlist
  * @param  order >=0 -ascending sort, <0 -descending sort
  * @return 0 -success, -1 -failure (e.g., invalid index)
  **/
int list_sort(sqlink list, int order);

/**
  * @brief  -de-duplication, delete duplicate elements from list
  * @param  list -pointer to sqlist
  * @return pointer to new sqlist
  **/
sqlink list_dedup(sqlink list);

/**
  * @brief  -merge of two sqlists
  * @param  list_a -pointer to a sqlist
  * @param  list_b -pointer to b sqlist
  * @return pointer to new sqlist
  **/
sqlink list_merge(sqlink list_a, sqlink list_b);

/**
  * @brief  -cross of two sqlists
  * @param  list_a -pointer to a sqlist
  * @param  list_b -pointer to b sqlist
  * @return pointer to new sqlist
  **/
sqlink list_cross(sqlink list_a, sqlink list_b);

/**
  * @brief  -union of two sqlists
  * @param  list_a -pointer to a sqlist
  * @param  list_b -pointer to b sqlist
  * @return pointer to new sqlist
  **/
sqlink list_union(sqlink list_a, sqlink list_b);

#endif