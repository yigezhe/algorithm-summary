/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: BubbleSortUseTheLogo.cpp
 * 创建日期: 2014年12月09日 星期二 07时43分09秒
 * 程序想法： 这是维基百科中冒泡排序一页，使用标志的ｃ语言实现的代码，我想看看它是如何运转的！
 * 成功地添加了一个我的想法
 */
#include <iostream>
#include <cstdio>
using namespace std;


void printarray(int a[], int size);
void bubble_sort(int d[], int size);
void translation(int a[], int size);
void test_translation();
void test_bubble_sort();
void test_sizeof_array();

void printarray(int a[], int size) {
    for (int i = 0; i < size; i++)
	cout << a[i] << ' ';
    cout << endl;
}

void bubble_sort(int d[], int size) {
    //printf("sizeof(d)=%lu\n",sizeof(d));//int d[],应该是声明了一个新的变量！//这里输入方程中ｓｉｚｅｏｆ（ａ）！＝ｓｉｚｅｏｆ（d)//但是我现在还找不到原因！
    //printf("sizeof(*d)=%lu\n",sizeof(*d));

    int theMostFarAwayExchange = size - 1;	//起始的最远的交换位置，这个位置是不用到达的，因为我们使用的是ｉ＜ｂｏｕｎｄ

    while (theMostFarAwayExchange) {
	//#记录下发生数据交换的位置#%
	int bound = theMostFarAwayExchange;

	theMostFarAwayExchange = 0;	// theMostFarAwayExchange变量的初始值总设定为０，就是我们没有出现交换，如果下面的ｆｏｒ循环出现了交换，我们就把theMostFarAwayExchange变量更改为当前交换所在的位置，ｆｏｒ循环结束以后，theMostFarAwayExchange就会变为最远位置的那一次交换的位置！
	//至少要进行一次全程查找！
	for (int i = 0; i < bound; i++) {

	    if (d[i] > d[i + 1]) {
		//#交换#%
		printarray(d, size);
		int t = d[i];
		d[i] = d[i + 1];
		d[i + 1] = t;
		printarray(d, size);
		printf("\n");
		theMostFarAwayExchange = i;
		//这里记录的是交换最远发生在哪里，以后我们从头找，只需要找到这个最远出处就可以停止，不用超过这个最远处去交换排序！
	    }
	}

	printf("translation happen from %d!\t",theMostFarAwayExchange+1);
	printarray(d, size);
	translation(d, theMostFarAwayExchange+1);
	printarray(d, size);
    }

}
void translation(int a[], int size) {
    //一个简单的实现方法是，对数组进行一次复制，但是，这种复制一直出现在循环里，问题比较大！
    /*
       a[1]=a[0];
       a[2]=a[1];
       ..........
       a[size-2]=a[size-3];
       a[size-1]=a[size-2];
       a[0]=a[size-1];
       有办法了
       a[size-1]=a[size-2];
       a[size-2]=a[size-3];
       ..........
       a[2]=a[1];
       a[1]=a[0];
       反过来以后，只要把ａ［ｓｉｚｅ－１］一备份就可以！
       a[0]=a[size-1];
     */
    int i;
    int asize1_origin = a[size - 1];
    for (i = size - 1; i > 0; i--) {
	a[i] = a[i - 1];
    }
    a[0] = asize1_origin;


}
void test_translation() {
    int a[5] = { 1, 2, 3, 4, 5 };
    printarray(a, 5);
    translation(a, 5);
    printarray(a, 5);

}

void test_sizeof_array() {
    int x[0];
    printf("sizeof(x)=%lu\nsizeof(*x)=%lu\n", sizeof(x), sizeof(*x));
    int y[1];
    printf("sizeof(y)=%lu\nsizeof(*y)=%lu\n", sizeof(y), sizeof(*y));
    int z[2];
    printf("sizeof(z)=%lu\nsizeof(*z)=%lu\n", sizeof(z), sizeof(*z));
}

void test_bubble_sort() {
    int a[] = { 5, 4, 3, 2, 1 };
    //int a[] = { 3, 2,1,4,5};
    //int a[] = { 3, 2, 4, 5, 1 };	//这个数据说明，如果最小数在后面，要经过好多交换，才可以把最小数提到最前面，这里应该有改进的方法！
    //一个办法：实现一次平移，３２４５１，５１交换后是，３２４１５,经过一次平移，变为１３２４５,这时有标记的冒泡排序才可以发挥它的优势，在下一次，只需要走到２
    printf("sizeof(a)=%lu\n", sizeof(a));
    printf("sizeof(*a)=%lu\n", sizeof(*a));

    bubble_sort(a, sizeof(a) / sizeof(*a));
}
int main() {
    //test_translation();
    test_bubble_sort();
    return 0;
}
