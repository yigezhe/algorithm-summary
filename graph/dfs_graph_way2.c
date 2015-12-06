//邻接表的深度递归算法
void DFS(GraphList g, int i) {
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c ", g->adjList[i].data);   //打印顶点，也可以其他操作
    p = g->adjList[i].firstedge;
    while(p) {
        if(!visited[p->adjvex]) {
            DFS(g, p->adjvex);           //对访问的邻接顶点递归调用
        }
        p = p->next;
    }
}

//邻接表的深度遍历操作
void DFSTraverse(GraphList g) {
    int i;
    for(i = 0; i < g.numVertexes; i++) {
        visited[i] = FALSE;
    }
    for(i = 0; i < g.numVertexes; i++) {
        if(!visited[i]) {
            DFS(g, i);
        }
    }
}
