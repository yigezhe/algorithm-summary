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
    //a b
    //b a mode b
    while(b!=0 ) {
    //printf("%d,%d\n",a,b);
        int tmp=a;
        a=b;
        b=tmp%b;
    }
    return a;
}
int main() {
	//gcd(4,6);
	int i,j;
	for(i=0;i<10;i++) {
		for(j=0;j<10;j++) {
			printf("%2d",gcd(i,j));
		}
		printf("\n");
	}
	return 0;
}
