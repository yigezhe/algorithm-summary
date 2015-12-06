#include<iostream>
#include<vector>
#define MAX_V 1000
//这里用的应该是邻接表！
using namespace std;
vector<int> G[MAX_V];
int main() {
    int V, E;
    scanf("%d%d",&V,&E);
    printf("V=%d,E=%d\n",V,E);
    for(int i=0; i<E; i++) {
        int s,t;
        scanf("%d%d",&s,&t);
        printf("s=%d,t=%d\n",s,t);
        G[s].push_back(t);
    }
    for(int i=0; i<V; i++) {
        for(int j=0; j<(int)G[i].size(); j++) {
            printf("%d-%d ",i,G[i][j]);
        }
        printf("\n");
    }

    return 0;
}
