//后进先出！
/*interface*/
/*interface implementation*/
#define N 100
#include<stdio.h>
int stack[N];
int head=0;
int tail=0;
void pop() {
    if(tail==0) {
        printf("栈已经是空的，不能释放出元素\n");
        return;
    } else {
        tail--;
    }
}
void push(int n) {
    if(tail>=N) {
        printf("栈已经满了，无法推入\n");
        return;
    } else {
        stack[tail]=n;
        tail++;
    }
}
int top() {
    if(tail==0) {
        printf("栈已经是空的，顶部没有元素\n");
        return -1;
    } else {
        return stack[tail-1];
    }
}
/*client*/
int main() {
    push(1);
    printf("top is %d\n",top());
    push(2);
    printf("top is %d\n",top());
    pop();
    printf("top is %d\n",top());
    pop();
    printf("top is %d\n",top());

    return 0;
}
