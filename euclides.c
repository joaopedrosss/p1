#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mdc(int a, int b){
    int r;
    if(a<b){//a menor que que b
        a = a + b;
        b = a - b;
        a = a - b;
    }
    r = a%b;
    if(r==0){
        return b;
    }
    mdc(b,r);
    
}


}

int cemN(int count,int a, int b){
    int k;
    if(count<=0){
    
        return 0;
    }
    scanf("%d %d",&a,&b);  
    printf("MDC(%d,%d) = %d\n",a,b,mdc(a,b));
    count -= 1;
    cemN(count,a,b);

}

int main() {
    int n;
    scanf("%d",&n);

    cemN(n,1,1);

}

