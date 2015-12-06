#include<stdio.h>
#include<math.h>
#include<complex.h>
int main() {
	//2x2 + 4x − 4 = 0
	double a,b,c;
	//a=2,b=4,c=-4;//两个实数解的例子！
	//a=1,b=1,c=-1;//两个实数解的例子！
	//a=1,b=-1,c=-1;//两个实数解的例子！
	a=1,b=-1,c=1;//两个实数解的例子！
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
		double x=(-b)/(2*a);
		double y=sqrt(-delta)/(2*a);

		double complex x1=x+y*I;
		double complex x2=x-y*I;
		printf("方程的两个复数解分别是");
		printf("%.2f%+.2fi", creal(x1),cimag(x1));
		printf(", ");
		printf("%.2f%+.2fi", creal(x2),cimag(x2));
		printf("\n");
		printf("方程的两个复数解的表示是{%f+-sqrt(%f)I}/%f\n",-b,-delta,2*a);
	}
	return 0;
}
