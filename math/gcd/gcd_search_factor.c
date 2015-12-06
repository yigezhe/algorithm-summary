//这个程序是有趣的，事后看，可以更简洁！
#include<stdio.h>
//我这里设置了MAX，如果程序中出现的数据超过了MAX，我就没有处理
//我现在的解决办法是：提示程序员来修改MAX的值!
#define MAX 100
int main() {
	//这里我先找出给定整数的因数
	int i;

	//打印出a的所有因数！
	int a=54;
	for(i=1;i<=a;i++) {
		if (a % i == 0) {
			printf(" %d",i);
		}
	}
	printf("\n");
	//打印出b的所有因数！
	int b=24;
	for(i=1;i<=b;i++) {
		if (b % i == 0) {
			printf(" %d",i);
		}
	}
	printf("\n");

	//打印出a和b的所有因数！
	int factor[MAX];
	int factors=0;
	for(i=1;i<=b || i<=a;i++) {
		if (a % i == 0 && b % i == 0) {
			printf(" %d",i);
			if (factors>=MAX) {
				printf("两个整数公因数的个数超过了预设的值%d\n",MAX);
				printf("请修改MAX的值来达到你的要求\n");
				return 1;
			}
			factor[factors]=i;
			factors++;
		}
	}
	printf("\n");

	for(i=0;i<factors;i++) {
			printf(" %d",factor[i]);
	}
	printf("\n");
	printf("gcd(%d,%d)=%d\n",a,b,factor[factors-1]);

	return 0;
}
