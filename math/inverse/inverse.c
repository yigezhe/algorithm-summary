#include<stdio.h>
int gcd(int a,int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	//保证最大公约数是正整数是必要的！
	if (a<0) return -a;
	else return a;
}
int main() {
	//第一我采用ax===b(mod m)的方程形式,而不是采用ax+b===0(mod m)的方程形式！
	int a,m;
	scanf("%d%d",&a,&m);

	//b%gcd(a,m)== 0 <=> 1 % gcd(a,m)==0 <==> gcd(a,m)==1
	if (gcd(a,m) != 1) {
		printf("Does not exist\n");
		return 0;
	}

	int s0=1,s1=0;
	int t0=0,t1=1;
	int r0=a,r1=m;
	fprintf(stderr,"%dx===1(mod %d)\n",a,m);
	int i=0;
	while(1) {
		int q1=r0/r1;
		int r2=r0-q1*r1;
		int s2=s0-q1*s1;
		int t2=t0-q1*t1;

		i++;
		r0=r1, r1=r2;
		s0=s1, s1=s2;
		t0=t1, t1=t2;

		if(r1==0) {
			break;
		}

	}
	
	//s0就是我们需要的！
	if (s0<0) { s0=s0+m; }
	printf("%d\n",s0);

	fprintf(stderr,"x===%d(mod %d)\n",s0,m);

	return 0;
}
