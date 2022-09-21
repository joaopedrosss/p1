#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


double relajus(double p, double sal){
    sal += sal*p;
    return sal;
}

int main() {
    double sal, nsal, p;

    scanf("%lf",&sal);

    if(sal >= 1500){
        p = 0.05;
        nsal = relajus(p,sal);
    }else if(sal>700 && sal<1500){
        p = 0.10;
        nsal = relajus(p,sal);
    }else if(sal>280 && sal<=700){
        p = 0.15;
        nsal = relajus(p,sal);
    }else{
        p = 0.2;
        nsal = relajus(p,sal);
    }
    printf("%.2lf\n%.0lf\n%.2lf\n%.2lf", sal, p*100, sal*p, nsal);
}