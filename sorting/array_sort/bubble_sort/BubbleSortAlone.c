/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: BubbleSortAlone.c
 * 创建日期: 2014年12月24日 星期三 05时30分21秒
 * 程序想法： 
  f:=false;
    for x:=1 to max-1 do
        if a[x]>a[x+1] then
            begin
                if f=false then d:=x;
                f:=true;
                t:=a[x];
                a[x]:=a[x+1];
                a[x+1]:=t;
                if x>1 then dec(x,2) else x:=0;
            end
        else
            if f=true then
                begin
                    x:=d;
                    f:=false;
                end;

 */
#include<stdio.h>
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

void input() {
}

void solve() {

}
void aloneBubbleSort(int a[], int n) {
    int f = 0;
    int i, d = 0;
    //pascal从１开始记数，在ｃ里就要从0开始了！
    //从头开始，一直找到倒数第二个！
    for (i = 0; i < n - 1; i++) {
	    printf("first reverse place at %d\t",d);
	printarray(a, n);
	/*
	printf("i=%d\t", i);
	printf("f=%d\t", f);
	printf("d=%d\t", d);
	*/
	if (a[i] > a[i + 1]) {

	    //f==0为逆序，ｆ＝＝１为逆序
	    if (f == 0) {
		d = i;		//这里记录第一次发生交换的地方？//对，就是记录第一次逆序产生的地方，这个程序可以这样想象，就是记录下第一次逆序产生的地方，然后继续寻找，遇到逆序就交换，遇到顺序就往下走，直到最后，然后在回到第一次逆序产生的地发来继续调整！
		//记录交换发生的起始位置！
		//我开始看到了这个算法是如何运行的！
	    }
	    printf("exchange(%d,%d)\n", a[i], a[i + 1]);
	    f = 1;
	    //这里实现了一个互换
	    int t = a[i];
	    a[i] = a[i + 1];
	    a[i + 1] = t;

	    //这里ｉ＝１，将产生ｉ＝－１，－１作为数组的下标是不允许的！
	    //但是进入到下一个循环式，ｆｏｒ循环的ｉ＋＋发挥了作用，使－１变为０就是从开头开始！
	    if (i > 0) {
		i -= 2;
	    } else {
		i = 0;
	    }
	    //printf("<i=%d>", i);
	} else {
		//f记录在当前位置是不是产生过逆序，如果有，作出下面的改变
	    if (f == 1) {

		i = d;
		f = 0;
	    }
	    //如果没有就正常的ｉ＋＋
	}
    }
}
void test_aloneBubbleSort() {
    int array[5] = { 5, 4, 3, 2, 1 };
    //int array[1] = { 1 };
    //int array[2] = { 1,2};
    int n=5;
    //测试还是要从最简单的开始，先理解一部分
    //随着测试的深入，最终把全部都理解了！
    printf("unsort before: ");
    printarray(array, n);
    aloneBubbleSort(array, n);
    //printarray(array, 5);
}

/*
    int array[2] = { 2,1};
    int array[3] = { 3,2,1};
    int array[3] = { 1,2,3};

    int array[4] = { 4,3,2,1};
    int array[4] = { 1,2,3,4};
*/

int main() {
    test_aloneBubbleSort();
    return 0;
}
