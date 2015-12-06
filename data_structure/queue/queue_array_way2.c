//这个代码的好处是比较节约空间！
#define N 1000
#include<stdio.h>

int queue[N];
int end=0;
void push(int element) {
    if (end==N) {
        fprintf(stderr,"end==N,不能添加元素了！\n");
    }else if (end>N) {
        fprintf(stderr,"end>N,queue[N]有元素了！\n");
    } else {
        queue[end]=element;
        end++;
    }
}
void pop() {
    if (0==end) {
        fprintf(stderr,"0==end,空的队列pop不出什么！\n");
    } else if(0>end) {
        fprintf(stderr,"0>end,end不知道什么时候变为了负数！\n");
    }else {
        //把整个数组向前推移！
        int i;
	//0,1,2,...,end-1
	//1,2,...,end-2
        for(i=0; i<end-1; i++) {
            queue[i]=queue[i+1];
        }
        end--;
    }
}
int front() {
    return queue[0];
}
int empty() {
    return 0==end;
}
int size() {
    return end;
}
void print() {
    if (0==end) {
        fprintf(stderr,"0==end,空的队列，没什么可打印的！\n");
    } else if (0 > end) {
        fprintf(stderr,"0>end,end不知道什么时候变成了负数！\n");
    } else {
        int i;
        for(i=0; i<end; i++) {
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
    printf("end=%d\n",end);
    push(4);
    print();
    printf("end=%d\n",end);
    printf("size = %d\n",size());

    return 0;
}
