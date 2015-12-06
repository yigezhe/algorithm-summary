//邻接表的广度遍历算法
void BFSTraverse(GraphList g) {
    int i;
    EdgeNode *p;
    Queue q;
    for(i = 0; i < g.numVertexes; i++) {
        visited[i] = FALSE;
    }
    InitQueue(&q);
    for(i = 0; i < g.numVertexes; i++) {
        if(!visited[i]) {
            visited[i] = TRUE;
            printf("%c ", g.adjList[i].data);   //打印顶点，也可以其他操作
            EnQueue(&q, i);
            while(!QueueEmpty(q)) {
                int m;
                DeQueue(&q, &m);
                p = g.adjList[m].firstedge;
                找到当前顶点边表链表头指针
                while(p) {
                    if(!visited[p->adjvex]) {
                        visited[p->adjvex] = TRUE;
                        printf("%c ", g.adjList[p->adjvex].data);
                        EnQueue(&q, p->adjvex);
                    }
                    p = p->next;
                }
            }
        }
    }
}
