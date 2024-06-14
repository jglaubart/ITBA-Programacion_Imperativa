// Escribir la función recursiva contarGrupos que reciba como únicos parámetros 
//un string (cadena de chars null terminated)  y un carácter. 
//La función debe retornar la cantidad de grupos de caracteres consecutivos iguales al carácter pasado por parámetro. 
//Un grupo está formado por uno o más caracteres iguales de manera consecutiva. 

// Si el string es "abbbccaadaaaa" y el carácter es 'a', la función debe devolver 3, ya que hay 3 grupos de caracteres 'a' formados por 1, 2 y 4 caracteres consecutivos respectivamente.
// Si el string es "34abcaa33 30 0" y el carácter es '3', la función debe devolver 3, ya que hay 3 grupos de caracteres '3' formados por 1, 2 y 1 caracteres consecutivos respectivamente.
// Si el string es "abbbccaadaaaa" y el carácter es 'x', la función debe retornar cero.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int contarGrupos(const char * s, char c){
    if( !s || *s == 0){return 0;}
    if(*s == c && *(s+1) != c){
        return 1 + contarGrupos(s+1, c);
    }
    return contarGrupos(s+1, c);
}


// Dada la siguiente definición de listas
	
// typedef struct node {
//       char head;
//       struct node * tail;
// };

// typedef struct node * TList;

// Escribir la función recursiva countGroups que reciba como únicos parámetros una lista de tipo TList y un carácter. 
// La función debe retornar la cantidad de grupos de caracteres consecutivos iguales al carácter pasado por parámetro.
//  Un grupo está formado por uno o más caracteres iguales en nodos consecutivos. 

typedef struct node {
      char head;
      struct node * tail;
} TNode;

typedef struct node * TList;

int countGroups(TList l, char c){
    if(l == NULL) {return 0;}
    if(l->tail == NULL){return (l->head == c) ? 1:0 ;}
    if(l->head == c && ( l->tail->head != c)){return 1 + countGroups(l->tail, c);}
    return countGroups(l->tail, c);
}

int main(void){
    assert(contarGrupos("abbbccaadaaaa", 'a') == 3);
    assert (contarGrupos("34abcaa33 30 0", '3') == 3);
    assert(contarGrupos("abbbccaadaaaa", 'x') == 0);
    contarGrupos("", 'x');

    TNode n12 = {'a', NULL};
    TNode n11 = {'a', &n12};
    TNode n10 = {'a', &n11};
    TNode n9 = {'a', &n10};
    TNode n8 = {'d', &n9};
    TNode n7 = {'a', &n8};
    TNode n6 = {'a', &n7};
    TNode n5 = {'c', &n6};
    TNode n4 = {'c', &n5};
    TNode n3 = {'b', &n4};
    TNode n2 = {'b', &n3};
    TNode n1 = {'b', &n2};
    TNode n0 = {'a', &n1};
    TList list = &n0;

   assert(countGroups(list, 'a') == 3);
   assert(countGroups(list, 'x') == 0);

 // Creación manual de la lista con el texto "34baca330 30 0"
    TNode node13 = {'0', NULL};
    TNode node12 = {' ', &node13};
    TNode node11 = {'0', &node12};
    TNode node10 = {'3', &node11};
    TNode node9 = {' ', &node10};
    TNode node8 = {'0', &node9};
    TNode node7 = {'3', &node8};
    TNode node6 = {'3', &node7};
    TNode node5 = {'a', &node6};
    TNode node4 = {'c', &node5};
    TNode node3 = {'a', &node4};
    TNode node2 = {'b', &node3};
    TNode node1 = {'4', &node2};
    TNode node0 = {'3', &node1};
    TNode * list2 = &node0;

    assert(countGroups(list2, '3') == 3);

    puts("OK!");
}