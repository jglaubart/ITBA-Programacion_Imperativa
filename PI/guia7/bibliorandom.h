//
//  random.h
//  random


#ifndef random_h
#define random_h
#include <stdlib.h>
#include <time.h>
 /**
  Numero real >=0 y < 1
  */
 double randNormalize(void);
 /**
  Numero entero en [izq, der]
  */
 int randInt(int izq, int der);
 double randReal(double izq, double der);
 //void randomize(void);
#define randomize() srand(time(NULL));

#endif /* random_h */
