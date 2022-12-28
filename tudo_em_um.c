#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int primo(int i,int n){
    if(i<=1){
        return 0;
    }
    if(i%n==0){
        return 0;
    }
    if(n==i-1){
        return 1;
    }
    primo(i,n+1);

}

int prox_primo(n){
    if(primo(n,2)){
        return n;
    }else{
        prox_primo(n+1);
    }
}

int mdc(int a, int b){
    int r;
    if(a<b){//a menor que que b
        a = a + b;
        b = a - b;
        a = a - b;
    }
    r = a%b;
    if(r==0){
        return b;
    }
    mdc(b,r);
    
}

int decompor(int n,int k){//
    int subs;
    subs = n;
    if(subs<10){
        k+=n;
        return k;
    }
    n = n%10;
    k+=n;
    decompor(subs/10,k);
}

int comprimo(int a, int b){
    if(mdc(a,b)==1){
        return 1;
    }else{
        return 0;
    }
}


int ler_dado(int k[], int o[], int s, int i){
    if(i==s){
        return 0;
    }
    scanf("%d %d",&o[i],&k[i]);
    ler_dado(k,o,s,i+1);
    
}


void correr(int a[],int s,int i){
    if(s==i){
        return;
    }
    /*printf("%d ",i);
    printf("%d\n",a[i]);*/
    correr(a,s,i+1);
}

void bb(int a[],int i,int n){
    if(i==n-1){
        return;
    }else{
        if(a[i]>a[i+1]){
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
         bb(a,i+1,n);
    }
}

void bsort(int a[],int n){
    if(n==1){
        return;
    }else{
        bb(a,0,n);
        bsort(a,n-1);
    }
    
}

int intervalo(int menor,int maior){
    if(menor<1){
        return 1;
    }else if(maior>1500){
        return 1;
    }else{
        return 0;
    }
}

int ler(int n){
    int jogadas;
    if(n==0){
        return 0;
    }else{
        scanf("%d",&jogadas);
        int kj[jogadas];
        int ord[jogadas];
        ler_dado(kj,ord,jogadas,0);

        bsort(ord,jogadas);
        bsort(kj,jogadas);
        correr(ord,jogadas,0);
        
        int invalido = 0;

        invalido += intervalo(ord[0],ord[jogadas-1]);
        invalido += intervalo(kj[0],kj[jogadas-1]);

        if(!invalido){
            int menor_ord = ord[0];
            int maior_ord = ord[jogadas-1];
            int meio_ord = ord[jogadas/2];

            int fat_ord = menor_ord+maior_ord+meio_ord;

            int cond_ord,prox;

            cond_ord = primo(fat_ord,2);
            cond_ord += comprimo(fat_ord,maior_ord);
            prox = prox_primo(fat_ord+1);
            cond_ord += primo(decompor(prox,0),2);

            int menor_kj = kj[0];
            int maior_kj = kj[jogadas-1];
            int meio_kj = kj[jogadas/2];
                    
            int fat_kj = maior_kj+menor_kj+meio_kj; 

            int cond_kj;

            cond_kj = primo(fat_kj,2);
            cond_kj += comprimo(fat_kj,maior_kj);
            prox = prox_primo(fat_kj+1);
            cond_kj += primo(decompor(prox,0),2);


            //printf("%d %d\n",fat_ord,fat_kj);
            //printf("%d %d\n",cond_kj,cond_ord);  

            if(cond_kj>cond_ord){ //kja ganhar
                printf("Kcaj %d\n",fat_kj);
            }else if(cond_kj<cond_ord){//ordep ganhar
                printf("Ordep %d\n",fat_ord);
            }else{
                printf("empate\n");
            }
        }else{
            printf("valor fora do limite!\n");
        }
        //printf("--%d---\n",invalido)      
        
        ler(n-1);
    }
};


int main() {
    int partidas;

    scanf("%d",&partidas);

    ler(partidas);

	return 0;
}