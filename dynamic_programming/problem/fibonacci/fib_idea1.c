
/*interface*/
/*interface implementation*/
/* simple recursive program for Fibonacci numbers */
int fib(int n) {
    if ( n <= 1 )
        return n;
    return fib(n-1) + fib(n-2);
}

/*client*/
#include<stdio.h>
int main() {
	//fib计算到44已经很慢了！
    int i;
    for(i=0; i<100; i++) {
        printf("f(%d)=%d\n",i,fib(i));
    }
    return 0;
}
