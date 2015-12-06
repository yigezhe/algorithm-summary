#include<stdio.h>
#define MAX_N 1000
int parent[MAX_N];
int rank[MAX_N];
void init(int n) {
    int i;
    for(i=0; i<n; i++) {
        parent[i]=i;
        rank[i]=0;
    }
}
void print(int n) {
    int i;
    for(i=0; i<n; i++) {
        printf(" %d<-%d(%d)",parent[i],i,rank[i]);
    }
    printf("\n");
}

int find(int x) {
    if(parent[x]==x) {
        return x;
	//这里是直接找到根！
    } else {
	    //查询过程中为什么还要改变值？
        return parent[x]=find(parent[x]);
    }
}
void unite(int x,int y) {
    x=find(x);
    y=find(y);
    if(x==y) return;//相同的根！
    if(rank[x]<rank[y]) {
        parent[x]=y;
    } else {
        parent[y]=x;
        if(rank[x]==rank[y])rank[x]++;//rank只在相等的时候加加？
    }
}
int same(int x,int y) {
    return find(x)==find(y);
}
int main() {
    init(7);
    unite(0,1);
    print(7);
    unite(0,4);
    print(7);
    unite(5,3);
    print(7);
    unite(3,6);
    print(7);
    unite(5,0);
    print(7);



    return 0;
}
