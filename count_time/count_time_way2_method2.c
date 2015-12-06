
/*interface*/
#include<stdio.h>
#include<time.h>
/*interface implementation*/
/*client*/
int main() {
    time_t start,stop;
    double duration;
    start=time(0);
    int sum=0;
    int i;
    for(i=0;i<10000;i++) {
	    sum+=i;
    }
    printf("sum = %d\n",sum);
    stop=time(0);
    //duration=((double)(stop-start))/CLK_TCK;
    duration=(double)difftime(stop,start);
    printf("time is %f\n",duration);
    return 0;
}
