//这里侧重存储边！
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn=100;
const int maxm=100;
struct NODE {
    int from;
    int to;
    int w;
};
NODE edge[maxm];
//这个数组是为了查询方便，而建立的，它存储起点为vi的第一条边的位置！
int head[maxn];
//这里还会对数组中的边，按起点排序！
bool cmp(NODE a,NODE b) {
    //这里是重边，其权值不同，就是相同方向有好几条边，每一条边都有一个权值！
    if(a.from==b.from && a.to==b.to) return a.w<b.w;
    if(a.from==b.from) return a.to<b.to;
    return a.from<b.from;
}
int main() {
    //n是点数，m是边数！
    int i,k;
    int n,m;
    cin>>n>>m;
    for(i=0; i<m; i++) {
        cin>>edge[i].from>>edge[i].to>>edge[i].w;
    }
    sort(edge,edge+m,cmp);
    memset(head,-1,sizeof(head));
    //顶点edge[0].from位于第一条边上！
    head[edge[0].from]=0;
    for(i=1; i<m; i++) {
        if(edge[i].from!=edge[i-1].from)
            head[edge[i].from]=i;
        //确定起点为vi的第一条边的位置
    }
    //顶点怎么从1开始！
    for(i=1; i<=n; i++) {
	    //打印起点为i的边！
        for(k=head[i]; edge[k].from==i&&k<m; k++) {
            cout<<edge[k].from<<" "<<edge[k].to<<" "<<edge[k].w<<endl;
        }
    }

    return 0;
}
