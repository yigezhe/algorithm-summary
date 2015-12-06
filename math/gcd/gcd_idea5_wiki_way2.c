//留下来把，这里的代码测试没有通过！
#include<stdio.h>
#include<math.h>
int gcd(int a,int b) {
    //printf("gcd(%d,%d)\n",a,b);
	if(a>b) {
		int tmp=a;
		a=b;
		b=tmp;
	}
    //printf("gcd(%d,%d)\n",a,b);
    //if(a<0) {a=-a;}
    //if(b<0) {b=-b;}
    // simple cases (termination)
    //if (a == b) return a;

    if (a == 0)
        return b;

    if (b == 0)
        return a;

    // look for factors of 2
    if (~(a & 1)) { // a is even
        if (b & 1) // b is odd
            return gcd(a>> 1, b);
        else // both a and b are eben
            return (gcd(a>> 1, b >> 1) << 1);
    }

    if (~(b & 1)) // a is odd, b is eben
        return gcd(a, b >> 1);

    // reduce larger argument
    if (a> b)
        return gcd((a- b) >> 1, b);

    else return gcd((b - a) >> 1, b);
}
int main() {
    //gcd(0,0); gcd(0,1); gcd(0,2); gcd(1,0); gcd(1,1); gcd(1,2); gcd(2,0); gcd(2,1); gcd(2,2);
    //gcd(4,6);
    int i,j;
    /*
    i=1,j=2;
    printf("gcd(%d,%d)=%2d\n",i,j,gcd(i,j));
    i=2,j=1;
    printf("gcd(%d,%d)=%2d\n",i,j,gcd(i,j));
    */
    for(i=0; i<10; i++) {
    for(j=0; j<10; j++) {
        //printf("gcd(%d,%d)=%2d\n",i,j,gcd(i,j));
        printf("%2d",gcd(i,j));
    }
    printf("\n");
    }
    return 0;
}
