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
	int a,b,m;
	scanf("%d%d%d",&a,&b,&m);

	if (b%gcd(a,m)!= 0) {
		fprintf(stderr,"%dx===%d(mod %d)没有整数解！\n",a,b,m);
		printf("Does not exist\n");
		return 0;
	}


	//求解具体的整数解
	//第一步先把a,b,m三者的公因数约掉！
	int g=gcd(gcd(a,b),m);
	a/=g;
	b/=g;
	m/=g;
	fprintf(stderr,"去掉%d,%d,%d三者的公因数%d后",a,b,m,g);
	fprintf(stderr,"，我们来求%dx===%d(mod %d)的整数解！\n",a,b,m);

	int s0=1,s1=0;
	int t0=0,t1=1;
	int r0=a,r1=m;
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
	
	fprintf(stderr,"%dx===1(mod %d)\n",a,m);
	fprintf(stderr,"x===%d(mod %d)\n",s0,m);
	int x=(s0*b)%m;
	if (x<0) x=m+x;
	printf("%d",x);

	//书中说有五个不同的解，我还是没有明白！
	//不过我可以在程序中实现之
	for(i=1;i<g;i++) {
		printf(",%d",x+i*m);
	}
	printf(" (mod %d)\n",m*g);

	return 0;
}
