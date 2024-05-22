#include <stdio.h>
#include "stackADTList.h"
#include <assert.h>

int main(void){
    stackADT stack1;
    stack1 = newStack();
    //assert(isEmpty(stack1));

    int elem = 10;
    push(stack1, elem);
    //assert(!isEmpty(stack1));
    //assert(pop(stack1)==10);
    //assert(isEmpty(stack1));

    free(stack1);

    return 0;
}