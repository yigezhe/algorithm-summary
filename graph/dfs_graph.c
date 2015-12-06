#define MAXVEX  100     //最大顶点数
typedef int Boolean;            //Boolean 是布尔类型，其值是TRUE 或FALSE
Boolean visited[MAXVEX];        //访问标志数组
#define TRUE 1
#define FALSE 0

//邻接矩阵的深度优先递归算法
void DFS(Graph g, int i) {
    int j;
    visited[i] = TRUE;
    printf("%c ", g.vexs[i]);                           //打印顶点，也可以其他操作
    for(j = 0; j < g.numVertexes; j++) {
        if(g.arc[i][j] == 1 && !visited[j]) {
            DFS(g, j);                  //对为访问的邻接顶点递归调用
        }
    }
}

//邻接矩阵的深度遍历操作
void DFSTraverse(Graph g) {
    int i;
    for(i = 0; i < g.numVertexes; i++) {
        visited[i] = FALSE;         //初始化所有顶点状态都是未访问过状态
    }
    for(i = 0; i < g.numVertexes; i++) {
        if(!visited[i]) {           //对未访问的顶点调用DFS，若是连通图，只会执行一次
            DFS(g,i);
        }
    }
}
