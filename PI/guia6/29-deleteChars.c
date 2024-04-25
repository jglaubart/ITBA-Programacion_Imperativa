#include <stdio.h>
#include <assert.h>
#include <string.h>

void deleteChars (char s1[], char s2[]){
    int dim1 = 0, dim2 = 0, i;
    int long1 = strlen(s1), long2 = strlen(s2);
    for (i = 0; i<long1 && i<long2; i++){
        if (s1[i] != s2[i]){
            s1[dim1++] = s1[i];
            s2[dim2++] = s2[i];
        }
    }
    while(i<long1){
        s1[dim1++] = s1[i++];
    }
     while(i<long2){
        s2[dim2++] = s2[i++];
    }
    s1[dim1] = '\0';
    s2[dim2] = '\0';
}

int main(void) {
  char string3[] = "abc";
  char string4[] = "axc123456789012345678901234567890";
  deleteChars(string3,string4);
  assert(strcmp(string3, "b")==0);
  assert(strcmp(string4, "x123456789012345678901234567890")==0);

  char s1[] = "Hola, soy un string";
  char s2[] = "Yo soy otro string";

  deleteChars(s1, s2);
  assert(strcmp(s1, "Hla, sy un string")==0);
  assert(strcmp(s2, "Y soy tro string")==0);

  char empty[] = "";
  deleteChars(s1, empty);
  assert(strcmp(s1, "Hla, sy un string")==0);
  assert(strcmp(empty, "")==0);

  strcpy(s1, "ABCDE");
  strcpy(s2, "abcde");
  deleteChars(s1, s2);
  assert(strcmp(s1, "ABCDE")==0);
  assert(strcmp(s2, "abcde")==0);

  deleteChars(s1,s1);
  assert(strcmp(s1, "")==0);
  
  char s3[] = "abc";
  char s4[] = "axc123456789012345678901234567890";
  deleteChars(s3,s4);
  assert(strcmp(s3, "b")==0);
  assert(strcmp(s4, "x123456789012345678901234567890")==0);


  puts("OK!");
  return 0;
}