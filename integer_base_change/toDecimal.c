#include<stdio.h>

int toDecimal(int n, int b) {
    int result=0;
    int multiplier=1;

    while(n>0) {
        result+=n%10*multiplier;
        multiplier*=b;
        n/=10;
    }

    return result;
}
int main() {
	int n=111;
	int b=2;
	printf("%d at %d = %d\n",n,b,toDecimal(n,b));
	return 0;
}
