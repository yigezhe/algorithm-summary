/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: BubbleSortBaiduEncyclopedia.c
 * 创建日期: 2014年12月03日 星期三 11时41分09秒
 */
#include<stdio.h>
#define SIZE 5

int number[SIZE];

void input() {
    /*
       number[0] = 5;
       number[1] = 4;
       number[2] = 1;
       number[3] = 7;
       number[4] = 8;
     */
    //这个数据最容易看出冒泡排序的工作原理！
    number[0] = 5;
    number[1] = 4;
    number[2] = 3;
    number[3] = 2;
    number[4] = 1;
}
void printarray() {
    int i;
    for (i = 0; i < SIZE; i++) {
	printf("%d\t", number[i]);
    }
    printf("\n");
}

	//n为数组a的元素个数
void bubble_sort(int a[], int n) {
    int i, j, temp;
    //这里对ｊ＝n －１不进行处理，是因为后面再没有可交换的了！
    //

    for (j = 0; j < n - 1; j++) {
	printf("\t一个系列交换前:");
	printarray();

	//这里是
	//j=0,n-1-j=n-1
	//ｊ等于零时，一直交换到ｎ－２项
	//ｊ等于１时，一直交换到ｎ－３项
	//...................
	//j等于ｎ－２时，一直交换到ｎ－１－（ｎ－２）－１项
	//就是ｊ等于ｎ－２时，只与第０项交换一下！
	//printf ("在%d到%d之间进行相邻交换\n", j, n - 1 - j - 1);      //没有大括号我加一个句子后，下面的句子就不执行了！
	for (i = 0; i < n - 1 - j; i++) {
	    //printf ("\t\t每一次交换前:");
	    //printarray ();
	    //由里向外观察比较好！

	    //这里是交换相邻项，我的不是我的是交换当前项！
	    //对交换相邻项才可以保证元素相同项总是相邻的！
	    if (a[i] > a[i + 1])	//数组元素大小按升序排列
	    {
		//左边的比右边的大就要交换，就是在相邻交换中把最大的找出来！
		//printf ("\t\t\t交换(a[%d],a[%d])=(%d,%d)\n",i,i+1,a[i],a[i+1]);
		temp = a[i];
		a[i] = a[i + 1];	//这里是交换到ｉ＋１，所以可以交换到，ａ［ｎ－１－ｊ－１＋１］=a[n-1-j],
		//当ｊ＝０时，我们可以交换到ａ［ｎ－１］,//这可以产生最大值
		//当ｊ＝1时，我们可以交换到ａ［ｎ－2］,//这可以产生倒数第二大的值
		a[i + 1] = temp;
	    }
	    //printf ("\t\t每一次交换后:");
	    //printarray ();
	    //printf ("\n");
	}
	printf("\t一个系列交换后:");
	printarray();
	printf("\n");
    }
}


void solve() {
    //printf ("排序前:");
    //printarray ();
    bubble_sort(number, SIZE);
    //printf ("排序后:");
    //printarray ();
}


int main() {

    input();
    solve();
    return 0;
}
