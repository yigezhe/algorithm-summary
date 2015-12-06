//维基百科中提供的一种方法适合计算机处理，华罗庚的方法适合手工计算！
#include<stdio.h>
#include<math.h>
#include<complex.h>
double curt(double a) {
	//curt means cube root
	return pow(a,1.0/3);
}
int main() {
	//这里只求实数解，不求复数解！
	double n=1;
	double a,b,c,d;
	a=1,b=3,c=2,d=-6*n;
	double complex u1=1;
	double complex u2=(-1+sqrt(3)*I)/2;
	double complex u3=(-1-sqrt(3)*I)/2;
	double delta=18*a*b*c*d-4*b*b*b*d+b*b*c*c-4*a*c*c*c-27*a*a*d*d;
	double delta0=b*b-3*a*c;
	double delta1=2*b*b*b-9*a*b*c+27*a*a*d;
	double complex C=curt((delta1+sqrt(delta1*delta1-4*delta0*delta0*delta0))/2);
	if(delta>0) {
		printf("方程有三个实数解！\n");
		if(delta0==0) {

		}
	} else if(delat==0) {
		printf("方程有一个实数解！\n");
		if(delta0==0) {
			printf("x123=%f\n",-b/(3*a));
		} else {
			printf("x12=%f\n",(9*a*d-b*c)/(2*delta0));
			printf("x3=%f\n",(4*a*b*c-9*a*a*d-b*b*b)/(a*delta0));
		}
	}else {
		printf("方程有一个实数解和两个对称复数解！\n");
	}
	
	printf("delta=%f\n",delta);
	printf("delta 0 =%f\n",delta0);
	printf("delta 1 =%f\n",delta1);
	double complex x1=-(b+u1*C+delta0/(u1*C))/(3*a);
	double complex x2=-(b+u2*C+delta0/(u2*C))/(3*a);
	double complex x3=-(b+u3*C+delta0/(u3*C))/(3*a);
	printf("x1=%f+%fi\n",creal(x1),cimag(x1));
	printf("x2=%f+%fi\n",creal(x2),cimag(x2));
	printf("x3=%f+%fi\n",creal(x3),cimag(x3));

	return 0;
}
