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
现阶段对这个程序的理解
这个程序以逆序出现点为界，后退一步检查，如果出现逆序就继续后退一步交换，如果没有逆序，就回到逆序交换点,继续前进重新确立逆序出现点，重复上面的思路！

从另一个角度来理解这个程序更好，a1<a2<a3,a4，就是说a1,a2,a3三个顺序是好的，a4还没有找到它的位置，如果a3<=a4,我们不用交换顺序是好的，如果a3>a4,这时我们通过从右向左的相互交换来帮助a4来找到自己的位置,找到后，我们可以用相同的思路来处理a5,这样每次只考察一个新元素，知道整个数组排列好．这个程序就是按照这个思路进行排序的！

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
    int haveReverse = 0;
    int i, firstReversePlace = 0;
    //pascal从１开始记数，在ｃ里就要从0开始了！
    //从头开始，一直找到倒数第二个！
    for (i = 0; i < n - 1; i++) {
	printf("连续逆序起始点：%d haveReverse=%d\n",
	       firstReversePlace, haveReverse);
	printf("ｉ= %d\t", i);
	printarray(a, n);
	/*
	   printf("i=%d\t", i);
	   printf("f=%d\t", f);
	   printf("d=%d\t", d);
	 */
	if (a[i] > a[i + 1]) {

	    //f==0为逆序，ｆ＝＝１为逆序
	    if (haveReverse == 0) {
		firstReversePlace = i;	//这里记录第一次发生交换的地方？//对，就是记录第一次逆序产生的地方，这个程序可以这样想象，就是记录下第一次逆序产生的地方，然后继续寻找，遇到逆序就交换，遇到顺序就往下走，直到最后，然后在回到第一次逆序产生的地发来继续调整！
		printf("\t连续逆序起始点被改变为：%d\n",
		       firstReversePlace);
		//对ｆｉｒｓｔＲｅｖｅｒｓｅＰｌａｃｅ的新理解，这个应该是连续逆序出现的起始位置，因为一旦出现顺序，ｉｓＦｉｒｓｔ就会被改变！
		//记录交换发生的起始位置！
		//我开始看到了这个算法是如何运行的！
	    }
	    printf("\t交换(%d,%d)\n", a[i], a[i + 1]);
	    haveReverse = 1;
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
	} else {
	    //f记录在当前位置是不是产生过逆序，如果有，作出下面的改变
	    //现在看来haveReverse变量其实实现的是有无逆序的一个检查，无逆序，就畅通无阻，有逆序就作出调整！
	    if (haveReverse == 1) {

		i = firstReversePlace;
		printf("i被变为：%d,被ｉ＋＋再一次改变！\n", i);
		haveReverse = 0;
		printf("haveReverse被还原为：%d\n", haveReverse);
	    }
	    //如果没有就正常的ｉ＋＋
	}
	printarray(a, n);
	printf("---------------------\n\n");
    }
}
void test_aloneBubbleSort() {
    //int array[1] = { 1 }, n=1;
    ////for循环中０＜1-０无法通过！
    //for循环中初始条件也要被检测！
    //int array[2] = { 1,2},n=2;
    //在ｆｏｒ循环中的１＜１处结束，由于一开始就没有逆序，所有的ｉｆ都没有作出改变！
    //int array[2] = { 2,1},n=2;
    //在ｆｏｒ循环中的１＜１处结束，一开始有逆序，但运行到下一个就碰上１＜１，其他代码还没来得及发挥作用！

    //int array[3] = { 1,2,3},n=3;//不用做任何处理！
    //int array[3] = { 3,1,2},n=3;//勉强理解！对打印做了更细化的理解！
    //int array[3] = { 3,2,1},n=3;
    //int array[4] = { 1,2,3,4},n=4;
    //int array[4] = { 2,1,3,4},n=4;
    //int array[4] = { 3, 2, 1, 4 }, n = 4;     //这个测试数据中可以看出，进行两次连续调换后，程序就会回到开头，重新开始进行调换！
    //int array[4] = { 1,2,4,3},n=4;//这个代码很智慧！
    //int array[5] = { 1,2,3,4,5},n=5;
    //int array[5] = { 1, 2, 5, 4, 3 }, n = 5;
    int array[5] = { 3, 2, 5, 4, 3 }, n = 5;
    //逆序出现，交换当前逆序，退一步，检查交换后，当前位置的数据与前一个数据的顺序是不是正确,正确就让ｉ变为记录的首次逆序出现点，测试下一个点，同时把haveReversee变为０，说明当前的顺序都好着．
    //这个程序是，出现逆序，就向前找一步，前一步如果还是逆序，继续向前找一步，如果不是，就退到，记录的首次逆序出现点，不论向前找多少步，只要出现顺序，就退到首次逆序出现点？这个观点需要验证！
    //测试还是要从最简单的开始，先理解一部分
    //随着测试的深入，最终把全部都理解了！
    printf("unsort before: ");
    printarray(array, n);
    aloneBubbleSort(array, n);
    //printarray(array, 5);
}
int main() {
    test_aloneBubbleSort();
    return 0;
}
