/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: BubbleSortMnemonic.c
 * 创建日期: 2014年12月08日 星期一 08时09分36秒
 * 程序想法：我把助记码部分的三个表达式写成程序！ 
 *  i∈ [0,N-1)                //循环N-1遍
 *  j∈ [0,N-1-i)            //每遍循环要处理的无序部分
 *     swap(j,j+1)          //两两排序（升序/降序）
 *
 *  i∈ [N-1,0)                //循环N-1遍
 *  j∈ [N-1,N-i-1)            //每遍循环要处理的无序部分
 *     swap(j,j-1)          //两两排序（升序/降序）
 *
 *  i∈ [0,N-1)                //循环N-1遍
 *  j∈ [i+1,N)            //每遍循环要处理的无序部分
 *     swap(i,j)          //两两排序（升序/降序）
 *
 */
#include<stdio.h>
void swap(int *Aj, int *Aj1) {
    int originAj = (*Aj);
    *Aj = (*Aj1);
    *Aj1 = originAj;
}
void printarray(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
	printf("%d ", a[i]);
    }
    printf("\n");
}

void bubblesort(int A[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
	    //i：0~n-2
	    //j:i+1~n-1
	    //0,1 0,2 ... 0,n-1
	    //1,2 1,3 ... 1,n-1
	    //.............
	    //n-3,n-2 n-3,n-1
	    //n-2,n-1
	    //这和我前面实现的一个代码相同！
	for (j = i+1; j < n; j++) {
	    if (A[i] > A[j]) {
		printarray(A, n);
		printf("%d~%d\t", i, j);
		printf("%d~%d\n", A[i], A[j]);
		swap(&A[i], &A[j]);
		printarray(A, n);
		printf("-----------------------\n");
	    }
	}
    }
}

void input() {
}

void testswap() {
    //先测试ｓｗａｐ函数是否正确！在去看排序算法是否正确
    int a = 1, b = 2;
    printf("%d %d\n", a, b);
    swap(&a, &b);
    printf("%d %d\n", a, b);
    //测试是成功的，说明我对指针还是熟悉的！
}
void solve() {
    testswap();
    int A[] = { 5, 1, 3, 4, 2 };
    bubblesort(A, 5);
}

int main() {
    input();
    solve();
    return 0;
}
