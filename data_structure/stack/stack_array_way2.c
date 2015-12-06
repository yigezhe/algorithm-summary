//这个方法没有好处，反倒增加了一些操作！
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
        int i;
        //1 2 3 4
        //2 3 4
        for(i=0; i<tail; i++) {
            stack[i]=stack[i+1];
        }
    }
}
void push(int n) {
    if(tail>=N) {
        printf("栈已经满了，无法推入\n");
        return;
    } else {
        int i;
        //1 2 3 4
        //n 1 2 3 4
        tail++;
        for(i=tail-1; i>0; i--) {
            stack[i]=stack[i-1];
        }
        stack[0]=n;
    }
}
int top() {
    if(tail==0) {
        printf("栈已经是空的，顶部没有元素\n");
        return -1;
    } else {
        return stack[0];
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
