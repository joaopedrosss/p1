#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int des(int a[],int size,int i){
    if(i==size){
        return 0;
    }
    printf("%d\n",a[i]);
    des(a,size,i+1);
}

int main(){
    int n[4] = {23,32,10,11};
    percorrer(n,4,0);
}