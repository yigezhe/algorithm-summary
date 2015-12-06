#include<stdio.h>
int main() {

	/*
	   我的递推公式
	   //我的逆推上去是r(-1)=b,r(-2)=a;
	r(-3)=a*q(-1)+b, 可以令r(-3)=0,q(-1)=0
	r(-3)=r(-2)*q(-1)+r(-1)
	a=b*q+r0 <=> r(-2)=r(-1)*q0+r0, r(-2)=a
	b=r0*q1+r1 <=> r(-1)=r0*q1+r1 , r(-1)=b
	r0=r1*q2+r2,q2=r/r1
	r1=r2*q3+r3

	ri=r(i+1)*q(i+2)+r(i+2), q(i+2)=ri/r(i+1)
	//这个无法作为递推公式！
	r(i+2)=ri-r(i+1)*q(i+2), q(i+2)=r1/r(i+1)
	//合并后得到！
	r(i+2)=ri-r(i+1)*(ri/r(i+1))//这个可以作为递推公式！//这个公式在两个公式中时相同的！

	r2=r0-r1*(r0/r1)//这个可以作为递推公式！

	r2=r0-r1*q2,q2=r0/r1

	我验证了一下，这个递推公式是对的！
	 */
	int a=25,b=8;
	int r0=a;
	int r1=b;
	int gcd_ab;
	while (1) {
		int q2=r0/r1;
		int r2=r0-r1*q2;
		printf("%d=%d-%d*%d\n",r2,r0,r1,q2);

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
