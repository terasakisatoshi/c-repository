#include <math.h>

double sin_degree(double x){
    const double pi=3.141592;
    const double deg_rad=pi/180.0;
    return(sin(x*deg_rad));
}