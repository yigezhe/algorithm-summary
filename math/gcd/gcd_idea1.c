//这个问题在考查gcd的实现！
#include<stdio.h>
//我用最简单的实现先试一下！
int gcd(int a,int b) {
    if(a<0) {
        a=-a;
    }
    if(b<0) {
        b=-b;
    }
    if(a==0) return b;
    if(b==0) return a;
    int gcd_ab=1;
    int i;
    for(i=2; i<=a; i++) {
        if(a%i==0 && b%i==0) {
            gcd_ab=i;
        }
    }
    return gcd_ab;
}

int main() {
    int i,j;
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            printf("%2d",gcd(i,j));
        }
        printf("\n");
    }
    return 0;
}
