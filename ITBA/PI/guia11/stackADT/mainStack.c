#include <stdio.h>
#include "stackADT.h"
#include <assert.h>
#include <stdlib.h>
int cmpInt(int n1, int n2){
    return n1==n2;
}
int main(void){
    stackADT stack1;
    stack1 = newStack(cmpInt);
    //assert(isEmpty(stack1));

    int elem = 10;
    push(stack1, elem);
    //assert(!isEmpty(stack1));
    //assert(pop(stack1)==10);
    //assert(isEmpty(stack1));

    free(stack1);

    puts("OK!");

    return 0;
}