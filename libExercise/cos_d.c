#include <stdio.h>
#include <math.h>

double cos_degree(double x){
    const double pi=3.141592;
    const double deg_rad=pi/180.0;
    return(cos(x*deg_rad));
}