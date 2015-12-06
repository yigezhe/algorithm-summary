//这里我要实现一下弃九法，这个方法可以用来验证两个整数相乘后的结果是不是正确！
//我觉得这个方法的价值是判断两个非常长的整数相乘的结果是不是正确，这是一个查错函数！
#include<stdio.h>
int mod9_sum(int a) {
	int mod9sum=0;
	while(a>0) {
		if (a%10 != 9) {
			//printf(" %d",a%10);
			mod9sum+=a%10;
		}
		a = a/10;
	}
	//printf("\n");
	return mod9sum%9;
}

int main() {
	//printf("请输入两个整数和其乘积,中间用一个空格隔开！\n");
	int a,b,P;
	scanf("%d%d%d",&a,&b,&P);

	int mod9a=mod9_sum(a);
	//printf("%d === %d\n",a,mod9a);
	int mod9b=mod9_sum(b);
	//printf("%d === %d\n",b,mod9b);

	int mod9P=mod9_sum(P);
	//printf("%d === %d\n",P,mod9P);

	if(mod9a*mod9b % 9 != mod9P) {
		//printf("这个乘积是错误的！\n");
		printf("Wrong\n");
		printf("%d*%d!=%d\n",a,b,P);
		printf("%d*%d==%d\n",a,b,a*b);
	} else {
		if (a*b==P){
			printf("Right\n");
		} else {
			printf("Pass\n");
			printf("%d*%d!=%d\n",a,b,P);
			printf("%d*%d==%d\n",a,b,a*b);

		}
	}

	return 0;
}
