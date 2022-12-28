#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Matriz de votação

int preechar(int pcs,int elts,int mat[pcs][elts]){
    int i = 0;
    int j = 0;
    while(j<elts){
        i = 0;
        while(i<pcs){
            scanf("%d ",&mat[i][j]);
            //printf("%d ",mat[i][j]);
            i++;
        }
        //printf("\n");
        j++;
    }

}

int main(){
    int princess,eleitores;
    scanf("%d",&princess);
    scanf("%d",&eleitores);
    int disney[princess][eleitores];
    preechar(princess,eleitores,disney);
    int soma = 0;
    int i, j;
    int count = 1;
    for(i=0;i<princess;i++){
        soma = 0;
        for(j=0;j<eleitores;j++){
            soma += disney[i][j];
        }
        printf("Princesa %d: %d voto(s)\n",count,soma);
        count++;
    }

}