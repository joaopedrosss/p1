
//Em Busca dos Trintão
//concerta a formatacao
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
double maisProx(double ac,double pc,double tc,double wc, double media){ 
    double ap,pp,tp,wp;//arthur-aproximacao
    ap = fabs(media-ac);
    pp = fabs(media-pc);
    tp = fabs(media-tc);
    wp = fabs(media-wc);

    if(ap < pp && ap < tp && ap < wp){
        return ac;
    }else if(pp < ap && pp < tp && pp < wp){
        return pc;
    }else if(tp < pp && tp < ap && tp < wp){
        return tc;
    }else{
        return wc;
    }

}

double qualOFator(double points){
    if(points>=0 && points<=20){
        return 0.2;
    }
    if(points>20 && points<=40){
        return 0.4;
    }
    if(points>40 && points<=60){
        return 0.6;
    }
    if(points>60 && points<=80){
        return 0.8;
    }else{
        return 1.0;
    }
}

int main() {
	/*'a' Arthur, 'p' Pedro, 't'  Túlio, 'w' Will e 'x' primeira rodada
    */
    double ap,pp,tp,wp,media,mp,fator,regular,pont;
    double ac,pc,tc,wc;//athur's choice ou escolha do arthur (ac)
    char campp[20];
    scanf("%lf %lf %lf %lf\n",&ap,&pp,&tp,&wp);//pontucacao
    scanf("%lf %lf %lf %lf\n",&ac,&pc,&tc,&wc);//escolha
    scanf("%s",campp);

    media = (ac+pc+tc+wc)/4;

    regular = sqrt((ac-media)*(ac-media) + (pc-media)*(pc-media)+ (tc-media)*(tc-media)+ (wc-media)*(wc-media));

    mp = maisProx(ac,pc,tc,wc,media);

    
    if(mp == ac){//a
        if(strcmp(campp,"a")==0){
            fator = qualOFator(ap);
            pont = 10 + fator*ap;
            printf("Arthur venceu outra vez!\n");
            printf("Pontuaão +%.2lf",pont);
        }else{
            ap += 10;
            printf("Arthur venceu!\n");
            printf("Pontuação: +10");
        }

    }else if(mp == pc){//p
        if(strcmp(campp,"p")==0){
            fator = qualOFator(pp);
            pont = 10 + fator*pp;
            printf("Pedro venceu outra vez!\n");
            printf("Pontuação: +%.2lf",pont);
        }else{
            pp += 10;
            printf("Pedro venceu!\n");
            printf("Pontuação: +10");
        }
    }else if(mp == tc){//t tp
        if(strcmp(campp,"t")==0){
            fator = qualOFator(tp);
            pont = 10 + fator*tp;
            printf("Tulio venceu outra vez!\n");
            printf("Pontuação: +%.2lf",pont);
        }else{
            tp += 10;
            printf("Pedro venceu!\n");
            printf("Pontuação: +10");
        }
    }else{//w wp
        if(strcmp(campp,"w")==0){
            fator = qualOFator(wp);
            pont = 10 + fator*wp;
            printf("Tulio venceu outra vez!\n");
            printf("Pontuação: +%.2lf",pont);
        }else{
            wp += 10;
            printf("Pedro venceu!\n");
            printf("Pontuação: +10");
        }

    }

    if(regular<=10){
        ap += 10;
        pp += 10;
        tp += 10;
        wp += 10;
        printf("\nHouve regularidade na rodada!\nTodos ganharam +10 pontos");
    }
   
}

/*
printf("media:%lf - mais proximo:%lf",media,mp);
    printf("\n%lf",regular);
    //printf("\n%lf",wp-42);
    //printf("%d\n",strcmp(campp,"w"));
    //strcmp(campp,"w")) retorna 1 se forem diferentes; retorna 0 se forem iguais.
    printf("ação");

*/