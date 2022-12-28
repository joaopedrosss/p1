#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int ciclo(int n, int c){
    //printf("%d\n",n);
    if(n==1){
        return c;
    }
    n = n%2==0 ? n/2 : 3*n+1;
    ciclo(n,c+1);
}
int max_ciclos(int i, int j, int mx){
    int tam;
    if(i>j){
        return mx;
    }
    tam = ciclo(i,1);
    mx = tam > mx ? tam : mx;
    max_ciclos(i+1,j,mx);

}

int ler() {
	int i,j,maior,ic,jc;
    if(scanf("%d %d",&i,&j)==EOF){
        return 0;
    }
    ic = i>j ? j : i;
    jc = i>j ? i : j;
    maior = max_ciclos(ic,jc,0);
    printf("%d %d %d\n",i,j,maior);
    ler();
}

int main(){
    ler();
}