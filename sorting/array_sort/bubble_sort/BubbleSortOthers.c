/*
 * 作者：
 * 作者邮箱：
 * 来自哪里：http://see.xidian.edu.cn/cpp/html/2443.html
 * 文件名: BubbleSortOthers.c
 * 创建日期: 2014年12月04日 星期四 19时49分30秒
 * 思考：在这个网站上，我还可以学习其他四个排序算法！这是可以参考的资料！
 */
#include<stdio.h>
#include<stdlib.h>
#define N 5
void bubble_sort_better(int a[], int n);
void bubble_sort(int a[], int n);
void solve();
void input();

int num[N];
void input() {
    num[0] = 5;
    num[1] = 4;
    num[2] = 1;
    num[3] = 2;
    num[4] = 3;
}

void solve() {
    bubble_sort(num, N);
    printf("better bubble sort\n");
    //恢复到原始数据！
    /*
    num[0] = 5;
    num[1] = 4;
    num[2] = 3;
    num[3] = 2;
    num[4] = 1;
    */
    num[0] = 5;
    num[1] = 4;
    num[2] = 1;
    num[3] = 2;
    num[4] = 3;

    bubble_sort_better(num, N);
}
void printarray() {
    int i;
    for (i = 0; i < N; i++)
	printf("%d ", num[i]);
    printf("\n");
}

//一般实现
//n为数组a的元素个数
void bubble_sort(int a[], int n) {
    //一定进行N-1轮比较
    int i;
    for (i = 0; i < n - 1; i++) {
	//每一轮比较前n-1-i个，即已排序好的最后i个不用比较
		printf("%d:\n",i);
	    int j;
	for (j = 0; j < n - 1 - i; j++) {
	    if (a[j] > a[j + 1]) {

		printf("\texchange(a[%d],a[%d])=(%d,%d)\n",j,j+1, a[j], a[j + 1]);
		printarray();
		int temp = a[j];
		a[j] = a[j + 1];
		a[j + 1] = temp;
		printarray();
	    }
	}
    }
}

//优化实现
//n为数组a的元素个数
void bubble_sort_better(int a[], int n) {
    //最多进行N-1轮比较
    int i;
    for (i = 0; i < n - 1; i++) {
	int isSorted = 1;
	//每一轮比较前n-1-i个，即已排序好的最后i个不用比较
		printf("%d:\n",i);//这里可以显示ｂｅｔｔｅｒ的好处！
	int j;
	for (j = 0; j < n - 1 - i; j++) {
	    if (a[j] > a[j + 1]) {
		isSorted = 0;
		printf("\texchange(a[%d],a[%d])=(%d,%d)\n",j,j+1, a[j], a[j + 1]);
		printarray();

		int temp = a[j];
		a[j] = a[j + 1];
		a[j + 1] = temp;
		printarray();
	    }
	}
	
	if (isSorted)
	    break;		//如果没有发生交换，说明数组已经排序好了
    }
}

int main() {

    input();
    solve();
    return 0;
}
