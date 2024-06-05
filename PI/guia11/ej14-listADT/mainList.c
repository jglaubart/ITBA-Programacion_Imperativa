#include "listADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static int cmp (elemType e1, elemType e2) {
    return e1-e2;
}

int
main(void) {
   listADT c = newList(cmp); // una lista, en este caso de int
   toBegin(c);
   assert(!hasNext(c));
   assert(!hasNextAsc(c));
   add(c, 3);   add(c, 1);   add(c, 5);   add(c, 2);
   toBegin(c);         // iterador por orden de insercià¸£à¸“n
   int n = next(c);    // n = 3
   assert(n==3);
   n = next(c);        // n = 1
   assert(n==1);
  
   toBeginAsc(c);      // iterador por orden ascendente

   assert(hasNext(c));
   assert(hasNextAsc(c));

   n = nextAsc(c);     // n = 1
   assert(n==1);

   n = next(c);        // n = 5
   assert(n==5);

   n = next(c);        // n = 2
   assert(n==2);
   assert(!hasNext(c)); 

   n = nextAsc(c);     // n = 2
   assert(n==2);

   n = nextAsc(c);     // n = 3
   assert(n==3);

   n = nextAsc(c);     // n = 5
   assert(n==5);

   assert(! hasNextAsc(c));

   freeList(c);

   puts("OK!");

   return 0;
}