#include <stdio.h>
#include "getnum.h"
int
main(void)
{
    float velms, velkm;
velms = getfloat("escriba una velocidad en m/s: ");
velkm = velms*3.6;
printf("%0.2f m/s son %0.2f km/h \n", velms, velkm);
}