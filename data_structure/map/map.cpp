#include<cstdio>
#include<map>
#include<string>
using namespace std;
int main() {
	map<int,const char *> m;
	m.insert(make_pair(1,"ONE"));
	m.insert(make_pair(10,"TEN"));
	m[100]="HUNDRED";
	map<int, const char*>::iterator ite;
	for(ite=m.begin();ite!=m.end();++ite) {
		printf("(%d: %s) ",ite->first,ite->second);
	}
	printf("\n");

	ite=m.find(1);
	puts(ite->second);

	ite=m.find(2);
	if(ite==m.end()) puts("not found 2");
	else puts(ite->second);

	puts(m[100]);
	//puts(m[2]);//这个代码同时实现的操作时，让2=null,进而把2加入了map！
	puts(m[1]);

	m.erase(10);
	for(ite=m.begin();ite!=m.end();++ite) {
		printf("(%d: %s) ",ite->first,ite->second);
	}
	printf("\n");
	return 0;
}
