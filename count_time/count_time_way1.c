
/*interface*/
#include<stdio.h>
#include<time.h>
/*interface implementation*/
/*client*/
int main() {
    clock_t start,stop;
    double duration;
    start=clock();
    int sum=0;
    int i;
    for(i=0;i<10000;i++) {
	    sum+=i;
    }
    printf("sum = %d\n",sum);
    stop=clock();
    //duration=((double)(stop-start))/CLK_TCK;
    duration=((double)(stop-start))/CLOCKS_PER_SEC;
    printf("time is %f\n",duration);
    return 0;
}
