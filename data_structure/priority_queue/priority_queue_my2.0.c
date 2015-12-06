//想法一：我觉得还是要在c级别来实现priority queue，而不是借助c加加的太多高级功能！

//没有做任何检查，就是实现一个基本的功能！
//1.2就要做出一些检查了！
//use 400M space
//即使最简单的事情，不亲自做一遍，也会错误百出！
//2.0里，我想要实现的是，让start始终是0
//2.1里我想为自己自定义的数据提供priority queue功能！
#define MAX 1000000
#include<stdio.h>
int queue[MAX];
int end=0;
void push(int element) {
	if (end==MAX) { fprintf(stderr,"不能添加元素了！\n"); }
	else if (end > MAX) { fprintf(stderr,"超过得更多了!\n"); }
	else {
		//想法一用插入法，因为插入前队列是排好的！
		//这是在queue2.0想法下插入！
		int i;
		for(i=0;i<end;i++) {
			if (element>queue[i]) continue;
			else {break;}
		}
		end++;
		int j;
		for(j=end-1;j>i;j--) {
			queue[j]=queue[j-1];

		}
		queue[i]=element;

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
			queue[i]=queue[i+1];
		}
		end--;
	}
}
int front(){
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
			printf(" %d",queue[i]);
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
	push(3); print();
	printf("size = %d\n",size());
	push(2); print();
	printf("size = %d\n",size());
	push(1); print();
	printf("size = %d\n",size());
	pop(); print();
	printf("size = %d\n",size());
	pop(); print();
	printf("size = %d\n",size());
	pop(); print();
	printf("size = %d\n",size());
	pop(); print();
	printf("size = %d\n",size());
	pop(); print();
	printf("end=%d\n",end);
	push(4);
	print();
	printf("end=%d\n",end);
	printf("size = %d\n",size());

	return 0;
}
