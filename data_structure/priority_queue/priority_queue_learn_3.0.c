//没有做任何检查，就是实现一个基本的功能！
//1.2就要做出一些检查了！
//use 400M space
//即使最简单的事情，不亲自做一遍，也会错误百出！
//2.0里，我想要实现的是，让start始终是0
//3.0里，我讲使用linkedlist来实现一个队列！
//这种方式实现的队列求队列的长度应该是一个操作挺多的事！
//正在研究！
#define MAX 2
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
struct node {
	int data;
	struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
void push(int data) {
	struct node* new_node = malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	if (head==NULL){
		//printf("add before head=%p,tail=%p\n",head,tail);
		//printf("tail next =%p\n",tail->next);
		//printf("tail data =%d\n",tail->data);
		tail=new_node;
		head=new_node;
		//printf("add after head=%p,tail=%p\n",head,tail);
	} else {
		if (data<=head->data) {
			new_node->next=head;
			head=new_node;
		} else {
			struct node* current = head;
			while(current->next != NULL && current->next->data < data){
				current = current->next;
			}
			new_node->next=current->next;
			current->next=new_node;

		}
	}
}
void pop(){
	printf("pop before head=%p,tail=%p\n",head,tail);
	struct node* tmp_head;  
	tmp_head = head;
	assert(tmp_head != NULL);  
	head= tmp_head->next; 
	printf("temp head = %p\n",tmp_head);
	if (tmp_head==tail) tail=NULL;
	free(tmp_head);  
	printf("pop after head=%p,tail=%p\n",head,tail);
}
int front(){
	return head->data;
}
int empty(){
	return head==NULL;
}
int size() {
	struct node* current = head;
	int count = 0;
	while(current != NULL) {
		count++;
		current = current->next;
	}

	return count;
}
void print(){
	struct node* current = head;
	while(current != NULL) {
		printf(" %d",current->data);
		current = current->next;
	}
	printf("\n");
}


int main() {
	/* 一个队列要实现以下几个功能！
	   There are four main operations on a queue:

	   Push – Adds an element to the back of the queue
	   Pop – Removes the front element from the queue
	   Front – Returns the front element on the queue
	   Empty – Tests if the queue is empty or not
	 */
	//我觉得保留last的地址，方便添加！
	push(4); print();
	printf("size = %d\n",size());
	push(3); print();
	printf("size = %d\n",size());
	push(2); print();
	printf("size = %d\n",size());
	pop(); print();
	printf("size = %d\n",size());
	pop(); print();
	printf("size = %d\n",size());
	pop(); print();
	printf("size = %d\n",size());
	//测试其对空的队列如何弹出
	//	pop(); print();
	//printf("size = %d\n",size());
	push(1); print();
	printf("size = %d\n",size());

	return 0;
}
