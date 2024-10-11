#include <stdio.h>


void vecdecimal (unsigned char vec[], int dim, int vecrta[]){
    for (int i = 0, j = 0; i<dim; i++, j+=2){
        vecrta [j] = vec[i]>>4;
        vecrta [j+1] = ((vec[i] & 0x0F));
    }
}


int main(){
    unsigned char vec[] = { 0x37, 0xF2, 0x03, 0x4A, 0xFF };
    int dim = sizeof(vec)/sizeof(vec[0]);

    int vecrta[2*dim];
    vecdecimal(vec, dim, vecrta);

    for (int i = 0; i<2*dim; i++){
        printf("%d ", vecrta[i]);
    }

    printf("\n");

}
