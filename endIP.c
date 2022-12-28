#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//leia 4 octetos de um enderço IP (binario)
//print o enderceo IP

int octe(int c,int value){
    int n;
    if(c==0){
        //printf("%d\n",value);
        return value;
    }
    scanf("%d ",&n);
    
    value += n*pow(2,c-1);
    c-=1;
    octe(c,value);
}

int ler(int n){
    int k;
    k = octe(8,0);
    if(n==1){
        printf("%d",k);
        return 0;
    }
    printf("%d.",k);
    n-=1;
    ler(c);
}

int main() {
    ler(4);
}