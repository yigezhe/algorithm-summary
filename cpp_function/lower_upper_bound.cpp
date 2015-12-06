#include<iostream>
#include<algorithm>
#define N 100
using namespace std;
int main() {
	int a[N];
	a[0]=1;
	a[1]=2;
	a[2]=3;
	a[3]=3;
	a[4]=3;
	a[5]=3;
	a[6]=4;
	a[7]=5;
	int n=8;
	int k=3;
	printf("same is %ld\n",upper_bound(a,a+n,k)-lower_bound(a,a+n,k));
	printf("upper=%ld\n",upper_bound(a,a+n,k)-a);
	printf("lower=%ld\n",lower_bound(a,a+n,k)-a);
	return 0;
}
