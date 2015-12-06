#include<stdio.h>
int main() {

	/*
	   维基百科上展示了一种推理公式！
	http://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
	r0=a
	r1=b
	r2=r0-q1r1

	这里让相乘的两个qr同步

	...

	r(i+1)=r(i-1)-qiri, and 0<=r(i+1)<abs(ri), qi=r(i-1)/ri
	我验证了一下，这个递推公式是对的！
	 */
	int a=25,b=8;
	int r0=a;
	int r1=b;
	int gcd_ab;
	while (1) {
		/*
		q(i+1)=ri/r(i+1);
		r(i+2)=ri-q(i+1)r(i+1)
		q(i+2)=r(i+1)/r(i+2)
		r(i+3)=r(i+1)-q(i+2)r(i+2)
		*/
		//我们需要保留两个值，并不断更新它们！
		int q1=r0/r1;
		int r2=r0-q1*r1;
		printf("%d=%d-%d*%d\n",r2,r0,q1,r1);

		//把以前的r0,r1换为r1和新算出来的r
		//直接换就是r0=r1;r1=r;
		r0=r1;
		r1=r2;
		if (r2==0) {
			gcd_ab=r0;
			break;
		}


	}
	printf("gcd(%d,%d)=%d\n",a,b,gcd_ab);

	return 0;
}
