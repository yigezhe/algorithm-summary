#include<stdio.h>
#include<math.h>
//这里只处理二维几何的向量！
#define N 2
int main() {
	int a[N];
	int b[N];
	//向量加法，就是对应元素相加，ai＋bi
	a[0]=1;a[1]=2;
	b[0]=3;b[1]=2;
	int cross_product=a[0]*b[1]-a[1]*b[0];
	printf("A B cross product is %d\n",cross_product);
	double a_length=sqrt(a[0]*a[0]+a[1]*a[1]);
	printf("A length is %f\n",a_length);
	double b_length=sqrt(b[0]*b[0]+b[1]*b[1]);
	printf("B length is %f\n",b_length);
	double sinab=cross_product/(a_length*b_length);
	printf("sin A B is %f\n",sinab);
	double ab_angle=asin(sinab);
	printf("A B angle is %f\n",ab_angle);
	double ab_area=cross_product;
	printf("A B parallelogram area is %f\n",ab_area);
	double ab_area2=cross_product/2;
	printf("A B triangle area is %f\n",ab_area2);


	return 0;
}
