#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Contando os Dígitos Pares

/*já sabemos decompor numeros só temos que pegar o numero de numeros pares*/
int checkPar(int n){
    return (n%2==0);
}

int decompor(int n,int k){//
    int subs;
    subs = n;
    if(subs<10){
        //printf("%d\n",subs);
        k+=checkPar(subs);
        printf("%d\n",k);
        //printf("retornando %d\n",checkPar(n));
        return k;
    }
    n = n%10;
    //printf("%d\n",n);   
    k += checkPar(n);
    decompor(subs/10,k);
    //printf("retornando %d\n",k);

}



int main() {
    int n,m;
    scanf("%d",&n);

    decompor(n,0);
}
