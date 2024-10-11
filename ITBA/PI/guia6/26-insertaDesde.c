#include <stdio.h>
#include <string.h>
#include <assert.h>

void insertaDesde(char * s1, const char * s2, char letra){
    int nuevadim = 0;
    while (s1[nuevadim] != letra){ nuevadim++; }

    int long2 = strlen(s2);
    for (int i = 0; i<long2; i++){
        s1[nuevadim++] = s2[i];
    }
    s1[nuevadim] = 0;
}

int main(void) {
    char str1[60] = "manuel";
    char str2[] = "javi";
    insertaDesde(str1, str2,'n');
    assert(strcmp(str1,"majavi")==0);

    char str3[20];
    strcpy(str3, "manuel");
    insertaDesde(str3, "javi" ,'l');
    assert(strcmp(str3,"manuejavi")==0);

    char str4[60];
    strcpy(str4, "lalala");
    insertaDesde(str4, "javi",'j');
    assert(strcmp("lalala",str4)==0);

    insertaDesde(str4, "javier ibaniez de toledo",'l');
    assert(strcmp("javier ibaniez de toledo",str4)==0);

    strcpy(str4,"12345");
    insertaDesde(str4, "6789abcdefgh",'5');
    assert(strcmp("12346789abcdefgh",str4)==0);


    puts("OK!");
    return 0;
}