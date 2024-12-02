#include "sqlist.h"

int main(int argc, char *argv[])
{
    sqlink lib = list_create();
    list_insert(lib, 0, 10);
    list_insert(lib, 0, 11);
    list_insert(lib, 0, 12);
    list_insert(lib, 0, 13);
    list_insert(lib, 0, 13);
    printf("length of lib: %d\n", list_length(lib));
    list_show(lib);

    list_delete(lib, 2);
    printf("length of lib: %d\n", list_length(lib));
    list_show(lib);

    list_modify(lib, 2, 99);
    printf("length of lib: %d\n", list_length(lib));
    list_show(lib);

    printf("find 0 in list: index = %d\n", list_find(lib, 0));
    printf("find 99 in list: index = %d\n", list_find(lib, 99));

    list_sort(lib, -1);
    printf("length of lib: %d\n", list_length(lib));
    list_show(lib);

    list_sort(lib, 99);
    printf("length of lib: %d\n", list_length(lib));
    list_show(lib);

    sqlink lib_b = list_create();
    list_insert(lib_b, 0, 14);
    list_insert(lib_b, 0, 15);
    list_insert(lib_b, 0, 13);
    list_insert(lib_b, 0, 13);
    list_insert(lib_b, 0, 15);
    list_insert(lib_b, 0, 12);
    list_insert(lib_b, 0, 12);
    list_insert(lib_b, 0, 13);
    list_insert(lib_b, 0, 14);
    list_insert(lib_b, 0, 15);
    list_insert(lib_b, 0, 12);
    list_insert(lib_b, 0, 13);
    list_insert(lib_b, 0, 13);
    list_insert(lib_b, 0, 14);
    list_insert(lib_b, 0, 12);
    list_insert(lib_b, 0, 15);
    printf("length of list: %d\n", list_length(lib_b));
    list_show(lib_b);

    sqlink lib_dedup = list_dedup(lib_b);
    list_sort(lib_dedup, 1);
    printf("length of list: %d\n", list_length(lib_dedup));
    list_show(lib_dedup);

    sqlink lib_union = list_union(lib, lib_b);
    list_sort(lib_union, 1);
    printf("length of list: %d\n", list_length(lib_union));
    list_show(lib_union);

    sqlink lib_cross = list_cross(lib, lib_b);
    list_sort(lib_cross, 1);
    printf("length of list: %d\n", list_length(lib_cross));
    list_show(lib_cross);

    free(lib);
    free(lib_b);
    free(lib_dedup);
    free(lib_union);
    free(lib_cross);
    return 0;
}