#include<iostream>
using namespace std;
const int maxn=100;
struct EdgeNode {
    int to;
    int w;
    EdgeNode * next;
};
struct VNode {
    int from;
    EdgeNode *first;
};
VNode Adjlist[maxn];
int main() {
    int n,m;
    cin>>n>>m;
    int i,j,w;
    int h;
    //读入m条边！
    for(h=0; h<m; h++) {
        cin>>i>>j>>w;
        EdgeNode * p= new EdgeNode();
        p->to=j;
        p->w=w;
        p->next=Adjlist[i].first;//第一次应该是NULL
        Adjlist[i].first=p;//Adjlist［i］。first保存着最后一次加入的邻接点的地址！
	//以备下一次加入！
	//这样一来先加入的应该最后面出现！
	//最后加入的在最前面显示！
	/*
	//i,j1
        p1->to=j1;
        p1->w=w1;
        p1->next=Adjlist[i].first;
        Adjlist[i].first=p1;
	//i,j2
        p2->to=j2;
        p2->w=w2;
        p2->next=p1;
        Adjlist[i].first=p2;
	*/
    }
    for(i=1; i<=n; i++) {
        for(EdgeNode *k=Adjlist[i].first; k!=NULL; k=k->next) {
            cout<<i<<" "<<k->to<<" "<<k->w<<endl;
        }
    }
    //如何删除申请到的内存！
    //我觉得双向链表更方便内存的释放！
    return 0;
}
