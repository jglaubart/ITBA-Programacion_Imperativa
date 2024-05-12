#include <stdio.h>
#include "getnum.h"

void palotes(int num){
    if (!num) {
        printf("\n");
        return;}
    printf("|");
    palotes(num-1);
}

int main(void){
    int num = getint("Ingrese la cantidad de palos: ");
    palotes(num);
}