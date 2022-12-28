#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int conversor(int n){
    if(n%2==0){
        printf(".");
    }else{
        printf("-");  
    }
}

int decompor(int n){
    int r;
    if(n<10){
        conversor(n);
        printf("\n");
        return 0;
    }
    r = n%10;
    conversor(r);
    decompor(n/10);
}

int ler(int cnt){
    int d;
    if(cnt==0){
        return 0;
    }
    scanf("%d",&d);
    decompor(d);
    cnt-=1;
    ler(cnt);
}

int main() {
    ler(10);
}