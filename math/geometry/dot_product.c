#include<stdio.h>
#include<math.h>
//这里只处理二维几何的向量！
#define N 2
int main() {
	int a[N];
	int b[N];
	//向量加法，就是对应元素相加，ai＋bi
	a[0]=1;a[1]=2;
	b[0]=1;b[1]=2;
	int dot_product=a[0]*b[0]+a[1]*b[1];
	printf("A B dot product is %d\n",dot_product);
	double a_length=sqrt(a[0]*a[0]+a[1]*a[1]);
	printf("A length is %f\n",a_length);
	double b_length=sqrt(b[0]*b[0]+b[1]*b[1]);
	printf("B length is %f\n",b_length);
	double cosab=dot_product/(a_length*b_length);
	printf("cos A B is %f\n",cosab);
	double ab_angle=acos(cosab);
	printf("A B angle is %f\n",ab_angle);
	return 0;
}
