/* dados 3 strings, se pide eliminar de s1 las letras que esten en s2 pero NO esten en s3 sin distinguir entre may y min */

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

#define CANT_LETTERS 26

void exclude( char * s1, const char * s2, const char * s3){
    char apariciones[CANT_LETTERS] = {0};
    for(int i=0; s2[i]; i++){
        if(isalpha(s2[i]))
            apariciones[tolower(s2[i]) - 'a'] = 1;
    }
    for(int i=0; s3[i]; i++){
        if(isalpha(s3[i]))
            apariciones[tolower(s3[i]) - 'a'] = 0;
    }
    int newDim=0;
    for(int i=0; s1[i]; i++){
        if(isalpha(s1[i]) && !apariciones[tolower(s1[i]) - 'a']) {
            s1[newDim++] = s1[i];
        }
        else if(!isalpha(s1[i])) {s1[newDim++] = s1[i];}
    }
    s1[newDim] = 0;
}

int main(){
    char s[] = "This is Seoul city Numerous miracles have come true";
    exclude(s, "teous tototototo nonononon", "the");
    assert(!strcmp(s, "Thi i el city mer miracle have cme tre"));

    char t[] = "This is Seoul city Numerous miracles have come true";
    exclude (t, "This is Seoul city Numerous miracles have come true","This s Sul cty Nerous mrcles ave come tru");
    assert(!strcmp(t, "This is Seoul city Numerous miracles have come true"));

    char y[] = "abc ABc";
    exclude(y, "", "");
    assert(!strcmp(y, "abc ABc"));

    puts("OK!");
}