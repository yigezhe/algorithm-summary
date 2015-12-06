#define N 1000
#include<stdio.h>
#include<stdlib.h>
int queue[N];
int start=0;
int end=0;
void push(int element) {
    if (end>=N) {
        //因为queue最多存储到queue[N-1]
        fprintf(stderr,"不能添加元素了！\n");
        exit(1);
    } else {
        queue[end]=element;
        end++;
    }
}
void pop() {
    if (start>end) {
        fprintf(stderr,"start > end????\n");
    } else if (start==end) {
        fprintf(stderr,"队列是空的，没有什么可以弹出！\n");
    } else {
        //只简单的处理办法，把队列前面的元素直接忽略，但是这样做比较浪费资源，但是比较节约时间和代码！
        start++;
    }
}
int front() {
    return queue[start];
}
int empty() {
    return start==end;
}
int size() {
    return end-start;
}
void print() {
    if (start>end) {
        fprintf(stderr,"end可以走到start的前面，肯定出错了！\n");
    } else {
        int i;
        for(i=start; i<end; i++) {
            printf("%d,",queue[i]);
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
    pop();
    print();
    printf("size = %d\n",size());
    pop();
    print();
    printf("size = %d\n",size());
    printf("start=%d end=%d\n",start,end);
    push(4);
    print();
    printf("size = %d\n",size());

    return 0;
}
