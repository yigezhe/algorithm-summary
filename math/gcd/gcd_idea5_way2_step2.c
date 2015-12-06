#include<stdio.h>
#include<math.h>
int gcd(int a,int b) {
    /*

    Input: a, b positive integers
    Output: g and d such that g is odd and gcd(a, b) = g×2d
    d := 0
    while a and b are both even do
        a := a/2
        b := b/2
        d := d + 1
    while a ≠ b do
        if a is even then a := a/2
        else if b is even then b := b/2
        else if a > b then a := (a – b)/2
        else b := (b – a)/2
    g := a
    output g, d
     */
    //保证在处理正整数！
	//The test for whether a number is divisible by two can be performed by testing the lowest bit in the number.
	//Division by two can be achieved by shifting the input number by one bit. 
    if(a<0) {
        a=-a;
    }
    if(b<0) {
        b=-b;
    }
    /*
    //保证a大于b
    if(b>a) {
        int tmp=a;
        a=b;
        b=tmp;
    }
    */
    if(a==0) { return b;}
    if(b==0) { return a;}
    int d=0;
    //在这里实现pow（2，d）
    int pow2d=1;
    while ((a&1)==0 && (b&1)==0) {
        a=a>>1;//a=a/2;
        b=b>>1;//b=b/2;
        d=d+1;
	pow2d=pow2d<<1;
    }
    while(a!=b) {
        if((a&1)==0) { a=a>>1;//a=a/2;
	}
        else if((b&1)==0) { b=b>>1;//b=b/2;
	}
        else if(a>b) { a=((a-b)>>1);//a=(a-b)/2;
	}
        else {
		b=((b-a)>>1);//b=(b-a)/2;
	}
    }
    int g=a;
    //return g*(int)pow(2,d);
    return g*pow2d;
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
