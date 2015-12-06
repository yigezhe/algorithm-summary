//邻接矩阵的广度遍历算法
void BFSTraverse(Graph g) {
    int i, j;
    Queue q;
    for(i = 0; i < g.numVertexes; i++) {
        visited[i] = FALSE;
    }
    InitQueue(&q);
    for(i = 0; i < g.numVertexes; i++) { //对每个顶点做循环
        if(!visited[i]) {             //若是未访问过
            visited[i] = TRUE;
            printf("%c ", g.vexs[i]); //打印结点，也可以其他操作
            EnQueue(&q, i);           //将此结点入队列
            while(!QueueEmpty(q)) {   //将队中元素出队列，赋值给
                int m;
                DeQueue(&q, &m);
                for(j = 0; j < g.numVertexes; j++) {
                    //判断其他顶点若与当前顶点存在边且未访问过
                    if(g.arc[m][j] == 1 && !visited[j]) {
                        visited[j] = TRUE;
                        printf("%c ", g.vexs[j]);
                        EnQueue(&q, j);
                    }
                }
            }
        }
    }
}
