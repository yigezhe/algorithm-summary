/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: BubbleSort.c
 * 创建日期: 2014年12月14日 星期日 04时57分22秒
 * 程序想法： 
Implementation
Pseudocode implementation

The algorithm can be expressed as (0-based array):

procedure bubbleSort( A : list of sortable items )
   n = length(A)
   repeat 
     swapped = false
     for i = 1 to n-1 inclusive do
       // if this pair is out of order //
       if A[i-1] > A[i] then
         // swap them and remember something changed //
         swap( A[i-1], A[i] )
         swapped = true
       end if
     end for
   until not swapped
end procedure
实现维基百科英文版ｂｕｂｂｌｅ　ｓｏｒｔ页面给出的这个伪代码！
能猜到的就没有必要记录，因为我需要投入当前的工作，而不是去学习英语单词！


 */
#include<stdio.h>

void input() {
}
//处于代码执行效率的考虑，没有必要实现一个swap函数，直接在代码中使用t=a,a=b,b=t!
//因为执行一个函数，比执行一个三个简单语句更花时间！
void swap(int *Aj, int *Aj1) {
    int originAj = (*Aj);
    *Aj = (*Aj1);
    *Aj1 = originAj;
}
void printarray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
	printf("%d ", array[i]);
    }
    printf("\n");
}
void bubbleSort(int array[], int size) {
    //size = length(array)
    int swapped = 0;
    do {
	swapped = 0;
	//这个程序的一个特点是，不去管后面已经排序好的部分，而是始终从头检查到尾部，我以前看过的程序都是把已经排序好的避开，只排没有排序好的！
	int i;
	for (i = 1; i <= size - 1; i++) {
	    // if this pair is out of order //
		printarray(array, size);
	    if (array[i - 1] > array[i]) {
		// swap them and remember something changed //
		swap(&array[i - 1], &array[i]);
		swapped = 1;	//这个检查是好的，是在算法的比较过程中的，我刚开始想的是单独写一个代码来判断数组是不是排列好了，现在看来，直接在算法步骤里体现，作出这个查找就可以！
//               这个检查是一个我以前没有注意到的！
	    }
		printarray(array, size);
	}
	printf("one round compare is end\n");
    } while (swapped);

}
void test_bubbleSort() {
    int array[5] = { 4, 2, 8, 7, 1 };
    //printarray(array, 5);
    bubbleSort(array, 5);
    //printarray(array, 5);
}
void solve() {
}

int main() {
    input();
    solve();
    test_bubbleSort();
    return 0;
}
