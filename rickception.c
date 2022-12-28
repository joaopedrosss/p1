#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int seq(int a,int b,int count){
    if(count%2==0){
        a+=3;
    }else{
        a+=a%5;
    }
    count+=1;
    if(count==b){
        return a;
    }
    seq(a,b,count);   
}

int main() {
    int a,b;
    scanf("%d\n%d",&a,&b);
    if(b==0){
        printf("%d",a);
    }else{
        printf("%d",seq(a,b,0));
    }
}