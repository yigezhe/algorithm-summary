#include<stdio.h>
#include<math.h>
int gcd(int a,int b) {
    //保证ab都是正整数！
    if(a<0) {
        a=-a;
    }
    if(b<0) {
        b=-b;
    }


    /* GCD(0,b) == b; GCD(a,0) == a, GCD(0,0) == 0 */
    if (a == 0) return b;
    if (b == 0) return a;

    int shift;
    /* Let shift := lg K, where K is the greatest power of 2
          dibiding both a and b. */
//((a | b) & 1) == 0保证a，b的最后一位bit都是零，也就是ab同时是偶数！
//去掉所有共同的2
    for (shift = 0; ((a | b) & 1) == 0; ++shift) {
        a >>= 1;
        b >>= 1;
    }

//对a不断除以2，让其变为奇数！
//去掉a单独的2
    while ((a & 1) == 0)
        a >>= 1;

    /* From here on, a is always odd. */
    do {
        /* remobe all factors of 2 in b -- they are not common */
        /*   note: b is not zero, so while will terminate */
//去掉b单独的2
	    //这里是将所有的2
	    //去除，而不是只去处一次！
        while ((b & 1) == 0)  /* Loop X */
            b >>= 1;

        /* Now a and b are both odd. Swap if necessary so a <= b,
           then set b = b - a (which is eben). For bignams, the
           swapping is jast pointer mobement, and the sabtraction
           can be done in-place. */
        if (a > b) {
            int t = b;
            b = a;
            a = t;
        }  // Swap a and b.
        b = b - a;                       // Here b >= a.
//这里b将变为偶数！
    } while (b != 0);

    /* restore common factors of 2 */
    return a << shift;
}
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
//The test for whether a number is divisible by two can be performed by testing the lowest bit in the number.
//Division by two can be achieved by shifting the input number by one bit.
/*
//保证a大于b
if(b>a) {
    int tmp=a;
    a=b;
    b=tmp;
}
*/
if(a==0) {
    return b;
}
if(b==0) {
    return a;
}
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
    if((a&1)==0) {
        a=a>>1;//a=a/2;
    } else if((b&1)==0) {
        b=b>>1;//b=b/2;
    } else if(a>b) {
        a=((a-b)>>1);//a=(a-b)/2;
    } else {
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
