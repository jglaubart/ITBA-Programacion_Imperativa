#include <stdio.h>
#include "utillist.h"
#include <assert.h>
#include <stdlib.h>

TList sortedList(TList list);
int main(void) {
    int v[] = { -10, -5, 0, 5, 10, 15, 20, 25};

    // Test para sortedList
    TList l1 = fromArray(v, 8);
    l1 = sortedList(l1);
    assert(checkElems(l1, v, 8));
    freeList(l1);

    int v2[] = { -10, -5, 0, 5, 10, 15, 20, 5};
    l1 = fromArray(v2, 8);
    l1 = sortedList(l1);
    int v3[] = { -10, -5, 0, 5};
    assert(checkElems(l1, v3, 4));
    l1 = sortedList(l1);
    assert(checkElems(l1, v3, 4));
    freeList(l1);

    int v4[] = { 10, 5, 8, 3, 10, 5, 2, 0};
    l1 = fromArray(v4, 8);
    l1 = sortedList(l1);
    assert(l1->elem==0 && l1->tail==NULL);
    freeList(l1);

    l1 = sortedList(NULL);
    assert(l1==NULL);

    puts("OK sortedList");
    return 0;
}

TList sortedList(TList list){
    if(list==NULL || list->tail == NULL){return list;}
    list->tail = sortedList(list->tail);
    if(list->elem >= list->tail->elem){
        TList devolver = list->tail;
        free(list);
        return devolver;
    }
    return list;
}