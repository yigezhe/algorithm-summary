
/*interface*/
#include<stdio.h>
#include<time.h>
/*interface implementation*/
/*client*/
int main() {
    double start,stop;
    double duration;
    start=(double)clock()/CLOCKS_PER_SEC;
    int sum=0;
    int i;
    for(i=0;i<10000;i++) {
	    sum+=i;
    }
    printf("sum = %d\n",sum);
    stop=(double)clock()/CLOCKS_PER_SEC;
    //duration=((double)(stop-start))/CLK_TCK;
    duration=stop-start;
    printf("time is %f\n",duration);
    return 0;
}
