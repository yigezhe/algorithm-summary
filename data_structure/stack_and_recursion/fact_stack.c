//后进先出！
/*interface*/
/*interface implementation*/
#define N 100
#include<stdio.h>
int stack[N];
int d[N];
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
int fact(int n) {
	if(n==0) return 1;
	else return n*fact(n-1);
}
/*client*/
int main() {
	int i=8;
	push(i);
	while(head<tail) {
		int a=top();
		if(a==0)  {
			d[0]=1;
			break;
		} else {
			i--;
			push(i);
		}
	}
	?
    return 0;
}
