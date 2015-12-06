//想法一：我觉得还是要在c级别来实现priority queue，而不是借助c加加的太多高级功能！

//没有做任何检查，就是实现一个基本的功能！
//1.2就要做出一些检查了！
//use 400M space
//即使最简单的事情，不亲自做一遍，也会错误百出！
//2.0里，我想要实现的是，让start始终是0
//2.1里我想为自己自定义的数据提供priority queue功能！
#define MAX 1000000
#include<stdio.h>
int end=0;
struct node {
	int cost;
	int at;
};
struct node queue[MAX];
void push(struct node element) {
	if (end==MAX) { fprintf(stderr,"不能添加元素了！\n"); }
	else if (end > MAX) { fprintf(stderr,"超过得更多了!\n"); }
	else {
		//想法一用插入法，因为插入前队列是排好的！
		//这是在queue2.0想法下插入！
		//这里的排列方法比较多，我按cost从小到大，at从小到大排列！
		int i;
		for(i=0;i<end;i++) {
			if (element.cost>queue[i].cost) continue;
			else if (element.cost==queue[i].cost) {
				if (element.at>queue[i].at) continue;
				else if (element.at==queue[i].at) {
					break;
				} else {
					break;
				}
			} else {
				break;
			}
		}
		end++;
		int j;
		for(j=end-1;j>i;j--) {
			queue[j].cost=queue[j-1].cost;
			queue[j].at=queue[j-1].at;

		}
		queue[i].cost=element.cost;
		queue[i].at=element.at;

		//用二分法也可以，
	}
}
void pop(){
	//end不能为负数！
	//end等于0时整个queue已经是空的了！
	if (0==end) { 
		//这里以错误信息显示比较合适！
		fprintf(stderr,"queue is empty, nothing will be pop!\n");
	} else if (0 > end) {
		fprintf(stderr,"end可以走到start的前面，这不可能！\n");
	} else {
		//就是把整个数组向前推移！
		//这时我们可以不关心start！
		int i;
		for(i=0;i<end;i++) {
			queue[i].cost=queue[i+1].cost;
			queue[i].at=queue[i+1].at;
		}
		end--;
	}
}
struct node front(){
	return queue[0];
}
int empty(){
	return 0==end;
}
int size(){
	return end;
}
void print(){
	if (0==end) { 
		//这里以错误信息显示比较合适！
		fprintf(stderr,"queue is empty, nothing will be pop!\n");
		return;
	} else if (0 > end) {
		fprintf(stderr,"end可以走到start的前面，这不可能！\n");
		return;
	} else {

		int i;
		for(i=0;i<end;i++) {
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
	struct node a; a.cost=2; a.at=2; push(a); print();
	struct node a2; a2.cost=1; a2.at=2; push(a2); print();
	pop(); print();

	return 0;
}
