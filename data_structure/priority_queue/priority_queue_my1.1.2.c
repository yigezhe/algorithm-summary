//没有做任何检查，就是实现一个基本的功能！
//1.2就要做出一些检查了！
//use 400M space
//即使最简单的事情，不亲自做一遍，也会错误百出！
//用queue1.0也可以实现对自定义数据的优先队列
//这里先不实现了，有一种就先用！
//1.1里实现自己定义的数据类型！
//1.1.2这里实现用二分法插入
#define MAX 1000000
#include<stdio.h>
struct node{
	int cost;
	int at;
};
struct node queue[MAX];
int start=0,end=0;

void push(struct node element) {
	if (end==MAX) { fprintf(stderr,"不能添加元素了！\n"); }
	else if (end > MAX) { fprintf(stderr,"超过得更多了!\n"); }
	else {
		int h=start,t=end;
		int m=(h+t)/2;
		while(h<t) {
			//h m element t
			if (queue[m].cost<element.cost) {
				h=m+1;
			} else {
				t=m-1;
			}
		}
		end++;
		int j;
		for(j=end-1;j>=h;j--) {
			queue[j].cost=queue[j-1].cost;
			queue[j].at=queue[j-1].at;

		}
		queue[h].cost=element.cost;
		queue[h].at=element.at;
	}
}
void pop(){
	//end不能为负数！
	//end等于start时整个queue已经是空的了！
	if (start==end) { 
		//这里以错误信息显示比较合适！
		fprintf(stderr,"queue is empty, nothing will be pop!\n");
	} else if (start > end) {
		fprintf(stderr,"end可以走到start的前面，这不可能！\n");
	} else {
		//只简单的处理办法，把队列前面的元素减一就可以！
		start++;
	}
}
struct node front(){
	return queue[start];
}
int empty(){
	return start==end;
}
int size(){
	return end-start;
}
void print(){
	if (start==end) { 
		//这里以错误信息显示比较合适！
		fprintf(stderr,"queue is empty, nothing will be pop!\n");
		return;
	} else if (start > end) {
		fprintf(stderr,"end可以走到start的前面，这不可能！\n");
		return;
	} else {

		int i;
		for(i=start;i<end;i++) {
			printf(" (%d,%d)",queue[i].cost,queue[i].at);
		}
		printf("\n");
	}
}


int main() {
	/* 一个队列要实现以下几个功能！
	   There are four main operations on a queue:

	   Push – Adds an element to the back of the queue
	   Pop – Removes the front element from the queue
	   Front – Returns the front element on the queue
	   Empty – Tests if the queue is empty or not
	 */
	struct node a1;
	a1.cost=2;
	a1.at=1;
	push(a1); print();
	printf("size = %d\n",size());

	struct node a2;
	a2.cost=1;
	a2.at=3;
	push(a2); print();
	printf("size = %d\n",size());

	a2.cost=7;
	a2.at=9;
	push(a2); print();
	printf("size = %d\n",size());

	pop();
	print();
	printf("size = %d\n",size());

	struct node select=front();
	printf("we get (%d,%d)\n",select.cost,select.at);


	return 0;
}
