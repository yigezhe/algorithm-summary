
#include<cstdio>
#include<stack>
using namespace std;
int main() {
	stack<int> s;
	s.pop();
	printf("%d\n",s.top());//初值是0

//	s.pop();//没有反应！
	s.push(1);
	s.push(2);
	s.push(3);
	printf("%d\n",s.top());
	s.pop();
	printf("%d\n",s.top());
	s.pop();
	printf("%d\n",s.top());
	s.pop();
	printf("%d\n",s.top());
	s.pop();
	printf("%d\n",s.top());

	return 0;
}
