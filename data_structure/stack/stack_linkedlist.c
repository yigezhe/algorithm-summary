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
void push(struct node** head_pointer,int data) {
    struct node* new_node = malloc(sizeof(struct node));
    if(new_node==NULL) {
        printf("我们没有为节点分配到空间\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = *head_pointer;
    *head_pointer = new_node;
}
void pop(struct node** head_pointer) {
    struct node* head;
    head = *head_pointer;
    assert(head != NULL);
    *head_pointer= head->next;
    free(head);
}
int front(struct node** head_pointer) {
    return (*head_pointer)->data;
}
int empty(struct node** head_pointer) {
    return *head_pointer==NULL;
}
int size(struct node* head) {
    struct node* current = head;
    int count = 0;
    while(current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}
void print(struct node* head) {
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
    struct node* head = NULL;
    push(&head,1);
    print(head);
    printf("size = %d\n",size(head));
    push(&head,2);
    print(head);
    printf("size = %d\n",size(head));
    push(&head,3);
    print(head);
    printf("size = %d\n",size(head));
    pop(&head);
    print(head);
    printf("size = %d\n",size(head));
    pop(&head);
    print(head);
    printf("size = %d\n",size(head));
    pop(&head);
    print(head);
    printf("size = %d\n",size(head));
    //测试其对空的队列如何弹出
    //pop(&head); print(head);
    //printf("size = %d\n",size(head));
    push(&head,4);
    print(head);
    printf("size = %d\n",size(head));

    return 0;
}
