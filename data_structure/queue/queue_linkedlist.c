//使用linkedlist来实现一个队列
#include<stdio.h>
#include<stdlib.h>
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
    if (head==NULL) {
        tail=new_node;
        head=new_node;
    } else {
        tail->next=new_node;
        tail=new_node;
    }
}
void pop() {
    if(head != NULL) {
        struct node* tmp_head;
        tmp_head = head;
        head= tmp_head->next;
        if (tmp_head==tail) tail=NULL;
        free(tmp_head);
    } else {
        fprintf(stderr,"对空的队列无法pop！\n");
    }
}
int front() {
    return head->data;
}
int empty() {
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
void print() {
    struct node* current = head;

    if(current != NULL) {
        printf("%d",current->data);
        current = current->next;
    }
    while(current != NULL) {
        printf(",%d",current->data);
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
    push(1);
    print();
    printf("size = %d\n",size());
    push(2);
    print();
    printf("size = %d\n",size());
    push(3);
    print();
    printf("size = %d\n",size());
    pop();
    print();
    printf("size = %d\n",size());
    pop();
    print();
    printf("size = %d\n",size());
    pop();
    print();
    printf("size = %d\n",size());
    //测试其对空的队列如何弹出
//	pop(); print();
    //printf("size = %d\n",size());
    push(4);
    print();
    printf("size = %d\n",size());

    return 0;
}
