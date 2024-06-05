#include <stdio.h>
#include <assert.h>
#include "queueADT.h"
 
int
main(void) {
    queueADT q = newQueue();
    queue(q, 5);
    queue(q, 9);
    queue(q, 3);
    int aux;
    dequeue(q, &aux);
    assert(aux == 5);
    dequeue(q, &aux);
    assert(aux == 9);
    queue(q, 1);
    dequeue(q, &aux);
    assert(aux == 3);
    dequeue(q, &aux);
    assert(aux == 1);
    assert(isEmpty(q) == 1);
    freeQueue(q);
    printf("OK 1!\n");

    queueADT q2 = newQueue();
    queue(q2, 5);
    queue(q2, 9);
    queue(q2, 3);
    toBegin(q2);
    assert(hasNext(q2) && next(q2) == 5);
    assert(hasNext(q2) && next(q2) == 9);
    assert(hasNext(q2) && next(q2) == 3);
    assert(hasNext(q2) == 0);
    int aux2;
    dequeue(q2, &aux2);
    assert(aux2 == 5);
    dequeue(q2, &aux2);
    assert(aux2 == 9);
    queue(q2, 1);
    dequeue(q2, &aux2);
    assert(aux2 == 3);
    dequeue(q2, &aux2);
    assert(aux2 == 1);
    assert(isEmpty(q2) == 1);
    toBegin(q2);
    assert(hasNext(q2) == 0);
    freeQueue(q2);
    printf("OK 2!\n");
    return 0;
}