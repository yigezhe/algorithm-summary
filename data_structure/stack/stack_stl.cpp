#include <iostream>
/*
Stack
A stack is one of the simplest data structures available. There are four main operations on a stack:

Push – Adds an element to the top of the stack
Pop – Removes the top element from the stack
Top – Returns the top element on the stack
Empty – Tests if the stack is empty or not
*/
//这个程序把这四个操作都实现了！
#include <stack>
using namespace std;

int main () {
    stack<int> mystack;
    int sum (0);

    for (int i=1; i<=10; i++)
	    mystack.push(i);

    while (!mystack.empty()) {
        sum += mystack.top();
        mystack.pop();
    }

    cout << "total: " << sum << endl;

    return 0;
}
