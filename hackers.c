#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//./a.out < input.txt

typedef struct Jogador{
    int linha;
    int coluna;
}JOGADOR;

int tiro(int tam,int campo[][tam],JOGADOR jogador,JOGADOR amigo,int passo_linha,int passo_coluna){
    int linha = jogador.linha;
    int coluna = jogador.coluna;

    while(linha>=0 && linha < tam && coluna>=0 && coluna < tam){
        printf("%d %d %d -\n",campo[linha][coluna],linha, coluna);
        if(amigo.linha == linha && amigo.coluna==coluna){
            return 0;
        }
        if(campo[linha][coluna] == 1){
            campo[linha][coluna] = 0;
            return 1;
        }
        linha += passo_linha;
        coluna += passo_coluna;
    }
    return 0;
}

int main(){
    JOGADOR azul;
    JOGADOR nosred;
    int azul_kills,nosred_kills = 0;

    int tam;
    scanf("%d",&tam);
    int campo[tam][tam];

    for(int i = 0;i<tam;i++){
        for(int j =0; j<tam;j++){
            scanf("%d ",&campo[i][j]);
        }
    }
    scanf("%d %d",&azul.linha,&azul.coluna);
    scanf("%d %d",&nosred.linha,&nosred.coluna);

    //sudir direita ; subir esquerda; descer diera; descer esquerda 
    azul_kills = tiro(tam,campo,azul,nosred,-1,-1) + tiro(tam,campo,azul,nosred,-1,1) + tiro(tam,campo,azul,nosred,1,1) + tiro(tam,campo,azul,nosred,1,-1); 

    //subir descer
    nosred_kills = tiro(tam,campo,nosred,azul,-1,0) + tiro(tam,campo,nosred,azul,1,0) + tiro(tam,campo,nosred,azul,0,1) + tiro(tam,campo,nosred,azul,0,-1);

    printf("aziul matou %d\n",azul_kills);
    printf("nosredna matou %d\n",nosred_kills);
    

    return 0;
}