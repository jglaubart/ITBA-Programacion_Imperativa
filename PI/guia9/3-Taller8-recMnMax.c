#include <stdio.h>
#include <assert.h>
 
void recMinMax(const int v[], int dim, int * min, int * max);
 
int 
main(void) {
    int v[] = {3, 1, 5, 2, 6, 99, -3, -4};
    int min, max;
    recMinMax(v, 0, &min, &max);
    assert(min == 0 && max == 0);
    recMinMax(v, 1, &min, &max);
    assert(min == 3 && max == 3);
    recMinMax(v, 2, &min, &max);
    assert(min == 1 && max == 3);
    recMinMax(v, 3, &min, &max);
    assert(min == 1 && max == 5);
    recMinMax(v, 6, &min, &max);
    assert(min == 1 && max == 99);
    recMinMax(v, 8, &min, &max);
    assert(min == -1 && max == -1);
    printf("OK!\n");
    return 0;
}

void recMinMax(const int v[], int dim, int * min, int * max){
     if(!dim){
        *min = 0;
        *max = 0;
        return; 
    }
    if(*v <= 0){
        *min = -1;
        *max = -1;
        return;
    }
    if(dim==1){
        *min = *v;
        *max = *v;
        return;
    }

    recMinMax(v+1, dim-1, min, max);
        *min = *v <(*min) ? *v : *min;
        if(*max>0){
        *max = *v >(*max) ? *v : *max;}
}