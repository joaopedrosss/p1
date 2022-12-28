#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//./a.out < input.txt
//simulado 1

typedef struct Npc{
    int linha;
    int coluna;
}NPC;

int direitaEsquerda(char k){
    if(k=='D'){
        return 1;
    }else if(k=='E'){
        return -1;
    }else{
        return 0;   
    }
}

int cimaBaixo(char k){
    
    if(k=='C'){
        return -1;
    } 
    if(k=='B'){
        return 1;
    }       
    return 0;
}

int main(){
    NPC peca;
    NPC coordenada;
    int linhas,colunas;
    scanf("%d %d",&linhas,&colunas);
    int tabu[linhas][colunas];
    
    for(int i = 0;i<linhas;i++){
        for(int j = 0;j<colunas;j++){
            scanf("%d ",&tabu[i][j]);
        }
    }
    
    int passos_final;
    scanf("%d\n",&passos_final);
    int passos_dados = 0;
    NPC passos[passos_final];
    char letra;
    
    for(int i = 0;i<passos_final;i++){
        scanf("%c\n",&letra);
       // printf("%c",letra);
        passos[i].linha = cimaBaixo(letra);
        passos[i].coluna = direitaEsquerda(letra);
        //printf("%d %d %d\n",passos[i].linha,passos[i].coluna,i);
    }
    scanf("%d %d",&coordenada.linha,&coordenada.coluna);
    int chegou = 0;
    peca.linha = 0;
    peca.coluna = 0;


    for(int j = 0; j<passos_final;j++){
        if(peca.linha == coordenada.linha && peca.coluna == coordenada.coluna){
            passos_dados=j+1;
            chegou = 1;
            break;
        }
        
        if(tabu[peca.linha + passos[j].linha][peca.coluna + passos[j].coluna] == 0){
            peca.linha += passos[j].linha;
            peca.coluna += passos[j].coluna;
        }else{
            tabu[peca.linha + passos[j].linha][peca.coluna + passos[j].coluna] -= 1;
        }
        printf("%d %d - %d %d\n",peca.linha,peca.coluna,passos[j].linha, passos[j].coluna);
        passos_dados=j+1;
    }
    if(peca.linha == coordenada.linha && peca.coluna == coordenada.coluna){
        chegou = 1;
    }
    if(chegou){
        printf("Cheguei com %d movimentos",passos_dados);
    }else{
        printf("Nao cheguei");
    } 
    

    
    return 0;
}