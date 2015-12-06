/*
   ax+by=gcd(a,b)

   这里的对应是
   a*s0+b*t0=r0=a, s0=1,t0=0
   a*s1+b*t1=r1=b, s1=0,t1=1
   a*s2+b*t2=r2, s2=s0-q1*s1,t2=t0-q1t1,q1=r0/r1
   r2=r0-q1r1,q1=r0/r1

   a*sN+b*tN=rN=gcd(a,b)
 */
#include<stdio.h>
int gcd(int a,int b) {
	int r0=a;
	int r1=b;
	int gcd_ab;
	while (1) {
		int q2=r0/r1;
		int r2=r0-r1*q2;

		//把以前的r0,r1换为r1和新算出来的r2
		r0=r1, r1=r2;
		if (r2==0) {
			gcd_ab=r0;
			break;
		}


	}
	return gcd_ab;
}
int main() {
	int a=240,b=46;
	int s0=1,s1=0;
	int t0=0,t1=1;
	int r0=a,r1=b;
	printf("%dx+%dy=%d\n",a,b,gcd(a,b));
	int i=0;
	while(1) {
		int q1=r0/r1;
		int r2=r0-q1*r1;
		int s2=s0-q1*s1;
		int t2=t0-q1*t1;

		i++;
		printf("%d: %d,%d,%d,%d\n",i,q1,r2,s2,t2);
		r0=r1, r1=r2;
		s0=s1, s1=s2;
		t0=t1, t1=t2;

		if(r1==0) {
			printf("%d*%d+%d*%d=%d\n",a,s0,b,t0,r0);
			break;
		}

	}
	return 0;
}
