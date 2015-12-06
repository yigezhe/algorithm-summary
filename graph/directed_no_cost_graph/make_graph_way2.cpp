#include<iostream>
#include<vector>
#define MAX_V 1000
//这里用的应该是邻接表！
using namespace std;
struct vertex {
	vector<vertex*>edge;
};
vertex G[MAX_V];

int main() {
    int V, E;
    scanf("%d%d",&V,&E);
    printf("V=%d,E=%d\n",V,E);
    for(int i=0; i<E; i++) {
        int s,t;
        scanf("%d%d",&s,&t);
        printf("s=%d,t=%d\n",s,t);
        G[s].edge.push_back(&G[t]);
    }

    return 0;
}
