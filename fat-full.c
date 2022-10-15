#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int fat(int n){
    if(n==0){
        return 1;
    }
    return n*fat(n-1);
}

int outO(int n){
    if(!n){
        return n;
    }
}

int inO(){
    int n,fatorial,count;

    scanf("%d",&n);
    if(n==-1){
        return 0;
    }
    //fatorial = fat(n);
    inO(); 
    printf("%d\n",fat(outO(n)));   
}

int main() {
    inO();
}

