#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int menor(int a, int b, int c, int d){
    return (a<b && a<c && a<d);
}

double pont(double p){
    double i;
    if(p<=20 && p>=0){
        i=0.2;
    }
    if(i>20 && p<=40){
        i=0.4; 
    }
    if(i>40 && p<=60){
        i=0.6; 
    }
    if(i>60 && p<=80){
        i=0.8; 
    }
    if(i>80){
        i=1; 
    }
    return (i*p);
}

int regular(double a){
    return a<100 && a>0;
}

int main() {
    double arthur,pedro,tulio,will;
    double anum,pnum,tnum,wnum,media,fator;
    char win[4];
    double adiff,pdiff,tdiff,wdiff;
    int rodada_valida = 0;

    scanf("%lf %lf %lf %lf",&arthur,&pedro,&tulio,&will);
    scanf("%lf %lf %lf %lf",&anum,&pnum,&tnum,&wnum);
    scanf("%s",&win); 
    printf("%d %d\n",win,"w");

    if(regular(anum) && regular(pnum) && regular(tnum) && regular(wnum)){
        rodada_valida=1;
    }

    if(rodada_valida){
        media = (anum+pnum+tnum+wnum)/4;    
        adiff = fabs(anum-media);
        pdiff = fabs(pnum-media);
        tdiff = fabs(tnum-media);
        wdiff = fabs(wnum-media);

        fator = sqrt(adiff*adiff + pdiff*pdiff + tdiff*tdiff + wdiff*wdiff);

        if(fator<=10){
            arthur+=10;
            pedro+=10;
            tulio+=10;
            will+=10;
        }

        if(menor(adiff,pdiff,tdiff,wdiff)){
            arthur+=10;
            if(1){
                printf("Arthur venceu outra vez!\nPontuação: %.2lf\n",pont(arthur));
            }else{
                printf("Arthur venceu!\nPontuação: +10\n");
            }
        }else if(menor(pdiff,adiff,tdiff,wdiff)){
            pedro+=10;
            if(1){
                printf("Pedro venceu outra vez!\nPontuação: %.2lf\n",pont(pedro));
            }else{
                printf("Pedro venceu!\nPontuação: +10\n");
            }
        }else if(menor(tdiff,pdiff,adiff,wdiff)){
            tulio+=10;
            if(1){
                printf("Túlio venceu outra vez!\nPontuação: %.2lf\n",pont(tulio));
            }else{
                printf("Túlio venceu!\nPontuação: +10\n");
            }
        }else if(menor(wdiff,pdiff,adiff,tdiff)){
            will+=10;
            if(1){
                printf("Will venceu outra vez!\nPontuação: +%.2lf\n",10+pont(will));
            }else{
                printf("Will venceu!\nPontuação: +10\n");
            }
        }else{
            printf("Não foi possível determinar um vencedor :/\nPróxima rodada.\n");
        }

        if(fator<=10){
            printf("Houve regularidade na rodada!\nTodos ganharam +10 pontos\n");
        }


    }else{
        printf("Números inválidos!\nPróxima rodada.\n");
    }
    
}