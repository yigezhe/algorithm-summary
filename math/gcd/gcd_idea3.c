#include<stdio.h>
int gcd(int a,int b) {
    //保证在处理正整数！
    if(a<0) {
        a=-a;
    }
    if(b<0) {
        b=-b;
    }
    if(b>a) {
        int tmp=a;
        a=b;
        b=tmp;
    }
    if(a==0) { return b; }
    if(b==0) { return a; }
    if ( a % b == 0) {
        return b;
    } else {
        return gcd ( b,a % b) ;
    }
}

int main() {
    //gcd(4,6);
    int i,j;
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            printf("%2d",gcd(i,j));
        }
        printf("\n");
    }
    return 0;
}
