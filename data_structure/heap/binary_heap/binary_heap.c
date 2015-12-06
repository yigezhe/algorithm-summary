#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_N 10000
//我们需要这里把heap的最前面的值设置为最大值！
int heap[MAX_N],sz=0;
void print() {
    int i;
    for(i=0; i<sz; i++) {
        printf(" %d",heap[i]);
    }
    printf("\n");
}
//sz==size
void push(int x) {
    //int i=sz++;
    int i=sz;
    sz++;
    while(i>0) {
        int p=(i-1)/2;
        if(heap[p]<=x) break;//父亲节点小于等于儿子节点就停止！
        heap[i]=heap[p];//新儿子节点上放上了父亲节点的值！
	printf("%d go to position %d\n",heap[p],i);
	print();
        i=p;
    }
    heap[i]=x;
}
int pop() {
    //ret is the varialbe that you want to return!
    int ret=heap[0];
    //int x=heap[--sz];
    sz--;
    int x=heap[sz];
	//printf("%d go to position %d\n",heap[a],i);
	//这里也只是提取了最后一个元素，但是这种提取也是没有必要的！

    int i=0;
    while(i*2+1<sz) {
        int a=i*2+1,b=i*2+2;
        if(b<sz && heap[b]<heap[a]) a=b;//保证左边儿子的值
	//这里不是保证左边儿子比右边儿子小，
	//只是取两个儿子中的最小值，来进行比较。
	//即使左边儿子比右边的大，这里也没有做出一种更换！
        if(heap[a]>=x) break;
        heap[i]=heap[a];
	printf("%d go to position %d\n",heap[a],i);
	print();
        i=a;
    }
    heap[i]=x;
    return ret;
}

int main() {
	push(1);
	push(2);
	push(4);
	push(7);
	push(8);
	push(5);
	print();
	//push(3);
	//print();
	pop();
	print();
    return 0;
}
