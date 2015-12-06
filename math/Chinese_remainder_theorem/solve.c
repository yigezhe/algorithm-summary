#include<stdio.h>
#define MAX 1000
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

int inverse(int a,int m) {
	if (gcd(a,m)!= 1) {
		fprintf(stderr,"%dx===1(mod %d)没有整数解！\n",a,m);
		return 0;
	}
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
	if (s0<0) s0=m+s0;
	return s0;
}
int main() {
	int b[MAX];
	int m[MAX];
	int i=0;
	char * line=NULL;
	size_t len=0;
	ssize_t read;
	while ((read = getline(&line, &len, stdin)) != -1) {
		//fprintf(stderr,"Retrieved line of length %zu :\n", read);
		//fprintf(stderr,"%s", line);
		sscanf(line,"%d%d",&(b[i]),&(m[i]));
		i++;
	}
	int j;
	fprintf(stderr,"我们将解决下面的同余式组\n");
	for(j=0;j<i;j++) {
		fprintf(stderr,"x===%d(mod %d)\n",b[j],m[j]);
	}

	int M[MAX];
	int M_all=1;
	for(j=0;j<i;j++) {
		M_all *= m[j];
	}

	fprintf(stderr,"M=%d\n",M_all);
	for(j=0;j<i;j++) {
		M[j] = M_all/m[j];
	}
	int M_inverse[MAX];
	for(j=0;j<i;j++) {
		M_inverse[j] = inverse(M[j],m[j]);
		fprintf(stderr,"%d*%d===1(mod %d)\n",M_inverse[j],M[j],m[j]);
	}

	int x=0;
	for(j=0;j<i;j++) {
		x%=M_all;
		x+=(b[j]*M_inverse[j]*M[j]%M_all);
		x%=M_all;
	}

	printf("%d(mod %d)",x,M_all);
	return 0;
}

