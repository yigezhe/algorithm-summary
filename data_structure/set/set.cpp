#include<cstdio>
#include<set>
using namespace std;

int main() {
	set<int> s;
	//加入元素
	s.insert(1);
	s.insert(3);
	s.insert(5);
	set<int>::iterator ite;

	for(ite=s.begin();ite!=s.end();++ite) {
		printf(" %d",*ite);
	}
	printf("\n");

	//查找元素
	ite=s.find(1);
	if(ite==s.end())puts("not found 1");
	else puts("found 1");

	ite=s.find(2);
	if(ite==s.end())puts("not found 2");
	else puts("found 2");

	if(s.count(3)!=0)puts("found 3");
	else puts("not found 3");

	if(s.count(2)!=0)puts("found 2");
	else puts("not found 2");

	//删除元素
	s.erase(3);

	for(ite=s.begin();ite!=s.end();++ite) {
		printf(" %d",*ite);
	}
	printf("\n");
	return 0;
}
