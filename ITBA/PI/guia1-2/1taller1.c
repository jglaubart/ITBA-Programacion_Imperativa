#include <stdio.h>
int main(void) 
{
    unsigned char var, var1, var2, var3, var4;
    var = 0xD8;
    var1 = (var>>6) & 0x03;
    var2 = (var>>4) & 0x03;
    var3 = (var>>2) & 0x03;
    var4 = var & 0x03;
    printf("%x \n%x \n%x \n%x\n", var1, var2, var3, var4);
    return 0;
    }