
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
    }else if(wp < pp && wp < ap && wp < tp){
        return wc;
    }else {
        return 0;
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

int vencedor(char campp[20], char letra[20],char nome[20],double pt){
    double pont,fator;
    if(strcmp(campp,letra)==0){
            fator = qualOFator(pt);
            pont = 10 + fator*pt;
            printf("%s venceu outra vez!\n",nome);
            printf("Pontuacao +%.2lf",pont);
    }else{
            pt += 10;
            printf("%s venceu!\n",nome);
            printf("Pontuacao: +10");
    }
    return 0;
}

int main() {
	// 'a' Arthur, 'p' Pedro, 't'  Túlio, 'w' Will e 'x' primeira rodada
    double ap,pp,tp,wp,media,mp,fator,regular,pont;
    double ac,pc,tc,wc;//athur's choice ou escolha do arthur (ac)
    char campp[20];
    scanf("%lf %lf %lf %lf\n",&ap,&pp,&tp,&wp);//pontucacao
    scanf("%lf %lf %lf %lf\n",&ac,&pc,&tc,&wc);//escolha
    scanf("%s",campp);

    if(ac,pc,tc,wc){

    }

    media = (ac+pc+tc+wc)/4;

    regular = sqrt((ac-media)*(ac-media) + (pc-media)*(pc-media)+ (tc-media)*(tc-media)+ (wc-media)*(wc-media));

    mp = maisProx(ac,pc,tc,wc,media);
    if(mp == ac){//a Arthur ap
        vencedor(campp,"a","Arthur",ap);
    }else if(mp == pc){//p Pedro pp
         vencedor(campp,"p","Pedro",pp);
    }else if(mp == tc){//t Tulio tp
        vencedor(campp,"t","Tulio",tp);
    }else if(mp == wc){
        vencedor(campp,"w","Will",wp);
    }else{
        printf("Nao foi possivel determinar um vencedor :/\n");
        printf("Proxima rodada.\n");
    }

    if(regular<=10){
        ap += 10;
        pp += 10;
        tp += 10;
        wp += 10;
        printf("Houve regularidade na rodada!\nTodos ganharam +10 pontos");
    }
   
}

