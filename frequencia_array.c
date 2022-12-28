#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void repita(int n,int i,int j[],int m[],int jf,int mf){
    int serie;
    if(n==i){
        printf("%d\n%d\n",jf,mf);
        return;
    }else{
        scanf("%d",&serie);

        if(serie%2==0){
            j[i] = serie;
            jf+=1;
        }else{
            j[i] = -1;
        }

        if(serie%2!=0){
            m[i] = serie;
            mf+=1;
        }else{
            m[i] = -1;
        }

        repita(n,i+1,j,m,jf,mf);
    }
}

int correr(int a[],int i, int s){
    if(i==s){
        return 0;
    }
    printf("%d\n",a[i]);
    correr(a,i+1,s);
}

int frequencia(int a[],int x,int s,int i,int f){
    if(i==s){
        return f;
    }
    if(a[i]==x){
        f += 1;
    }
    frequencia(a,x,s,i+1,f);
}

int digitos(int n,int k){//
    int subs;
    subs = n;
    if(subs<10){
        k+=n;
        return k;
    }
    n = n%10;
    k+=n;
    digitos(subs/10,k);
}
int decompor(int a[],int n,int i,int soma){
    if(i==n){
        return soma;
    }
    if(a[i]!=-1){
        if(frequencia(a,a[i],n,0,0)==1){
        soma += digitos(a[i],0);
        }
    }
    
    decompor(a,n,i+1,soma);
}


int main() {
    int n;
    scanf("%d",&n);
    int joao[n];
    int maria[n];
    repita(n,0,joao,maria,0,0);
    //correr(maria,0,n);
    int soma_maria;

    soma_maria = decompor(maria,n,0,0);

	return 0;
}