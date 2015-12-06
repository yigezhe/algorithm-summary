/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: BubbleSortThePseudo-code.c
 * 创建日期: 2014年12月08日 星期一 06时13分49秒
 * 程序想法：我实现一下，维基中文页面中冒泡排序中的一个伪代码！ 
 * function bubblesort (A : list[0..n-1]) {
    var int i, j;
    for i from n-2 downto 0 {//测试结果是作者的代码不对！正确的还是从零增长到ｎ－２，这样才能保证最大数是经过最多次的变换得到的！
        for j from 0 to n-1-i { 
            if (A[j] > A[j+1])
                swap(A[j], A[j+1])
        }
    }
}
 */
#include<stdio.h>
//这里有一个困惑，就是，ｓｗａｐ的实现必须使用指针！
//有困惑，先给出自己的一个解决办法，并测试，再去看网络上的办法，这是我的好的选择！
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
    //for (i = n - 2; i >= 0; i--) {
    //for (i = 0; i <= n - 2; i++) {
    for (i = 0; i < n - 1; i++) {
	    //数组是０～ｎ－１
	//i n-1-i-1
	//0 n-1-(0)-1=n-2
	//1 n-1-(1)-1=n-3
	//..............
	//n-3,n-1-(n-3)-1=1
	//n-2,n-1-(n-2)-1=0
	//
	//0~n-2,最远n-2与n-１交换
	//0~n-3
	//....
	//0~1
	//0~0,最远０与１交换
	//n-1-i,就是比较n-1之前的ｉ个元素！
	for (j = 0; j < n - 1 - i; j++) {
	    if (A[j] > A[j + 1]) {
		printf("A[%d],A[%d]change\t", j, j + 1);
		printf("==%d,%dchange\t", A[j], A[j + 1]);
		int k;
		for (k = 0; k < n; k++) {
		    printf("%d ", A[k]);
		}
		    printf("\t");

		swap(&A[j], &A[j + 1]);
		printarray(A, n);
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
    int A[] = { 5, 4, 3, 2, 1 };
    printarray(A, 5);
    bubblesort(A, 5);
}

int main() {
    input();
    solve();
    return 0;
}
