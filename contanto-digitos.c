#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Contando os Dígitos Pares

int checkPar(int n){
    return (n%2==0);
}

int decompor(int n,int k){//
    int subs;
    subs = n;
    if(subs<10){
        return k;
    }
    n = n%10;
    k += checkPar(n);
    decompor(subs/10,k);
}



int main() {
    int n,m;
    scanf("%d",&n);

    decompor(n,0);
}

