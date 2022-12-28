#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int ler(int cnt){
    int kj_v, kj_a, or_v,or_a;
    if(cnt==0){
        return 0;
    }
    scanf("%d %d",&kj_a,&kj_v);
    scanf("%d %d",&or_a,&or_v);

    
    cnt-=1;
    ler(cnt);

}

int main() {
    ler(2);
}