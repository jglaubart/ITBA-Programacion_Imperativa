#include <stdio.h>
#include <assert.h>
 
typedef int (*fn) (int, int);
int operatoria(int v[], size_t dim, int base, fn f);
 
int producto(int x, int y) {
    return x * y;
}
 
int suma(int x, int y) {
    return x + y;
}
 
int
main(void) {
    int v1[] = {2,3,4,5};
    assert(operatoria(v1, 4, 1, producto) == 120);
    assert(operatoria(v1, 4, 0, suma) == 14);
 
    printf("OK!\n");
    return 0;
}

int operatoria(int v[], size_t dim, int base, fn f){
    if(!dim){ return base; }
    return f(v[0], operatoria(v+1, dim-1, base, f));
}