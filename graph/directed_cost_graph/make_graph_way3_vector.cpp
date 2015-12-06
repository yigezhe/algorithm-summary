#include<iostream>
#include<vector>
using namespace std;
const int maxn=100;
struct EdgeNode {
    int to;
    int w;
};
vector<EdgeNode>map[maxn];
int main() {
    int n,m;
    cin>>n>>m;
    int i,j,w;
    int h;
    //读入m条边！
    for(h=0; h<m; h++) {
        cin>>i>>j>>w;
        EdgeNode e;
        e.to=j;
        e.w=w;
	map[i].push_back(e);
    }
    for(i=1; i<=n; i++) {
        for(vector<EdgeNode>::iterator k=map[i].begin();k!=map[i].end();k++) {
		EdgeNode t=*k;
            cout<<i<<" "<<t.to<<" "<<t.w<<endl;
        }
    }
    //如何删除申请到的内存！
    //我觉得双向链表更方便内存的释放！
    return 0;
}
