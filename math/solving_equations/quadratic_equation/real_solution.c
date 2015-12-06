#include<stdio.h>
#include<math.h>
int main() {
	//2x2 + 4x − 4 = 0
	double a,b,c;
	a=2,b=4,c=-4;//两个实数解的例子！
	if(a==0) {
		printf("这不是一个二次方程！\n");
	}
	double delta=b*b-4*a*c;
	if(delta>0) {
		double x1=(-b+sqrt(delta))/(2*a);
		double x2=(-b-sqrt(delta))/(2*a);
		printf("方程的两个实数解分别是%f,%f\n",x1,x2);
		printf("方程的两个实数解另一种表示是{%f+-sqrt(%f)}/%f\n",-b,delta,2*a);
	} else if(delta==0) {
		double x12=(-b)/(2*a);
		printf("方程的一个实数解是%f\n",x12);
	} else {
		printf("方程的两个复数解的表示是{%f+-sqrt(%f)I}/%f\n",-b,-delta,2*a);
	}
	return 0;
}
