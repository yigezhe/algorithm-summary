int  GraphDijk(struct Graph *g, int root, int *parent, int *distance) {
    // 将除根结点之外的点都放入堆中，设置所有键为INFINITY
    // 遍历根结点发出的边，将其最短路径设为相应权值，并维持堆性质
    // RemoveTop，此结点已经取最短路径，如果为INFINITY，则终止算法
    // 否则，将其状态设为已标记，并设为根结点
    // loop back
    parent[root] = root;
    int reflection[g->V];
    int heap_real[g->V - 1];
    for (int i=0,j=0; i < g->V; i++) {
        if (i == root) {
            distance[i] = 0;
        } else {
            distance[i] = INFINITY;
            heap_real[j++] = i;
            reflection[i] = j;
        }
    }

    struct Edge *e;
    struct list_t *iter;
    int *heap = heap_real - 1;
    int base = 0;  /* euqal to distance[root]  */
    int size = g->V - 1;
    int length;
    do {
        iter = list_next(&(g->vertices + root)->link);
        for (; iter; iter = list_next(iter)) {
            e = list_entry(iter, struct Edge, link);
            length = base + e->weight;
            if (length < distance[e->to]) {
                HeapDecreaseKey(heap, size,
                                distance, reflection,
                                reflection[e->to], length);
                parent[e->to] = root;
            }
        }
        root = HeapRemoveTop(heap, size, distance, reflection);
        base = distance[root];

        if (distance[root] == INFINITY) {
            /* remain nodes in heap  is not accessible */
            return g->V - (size + 1); /* 返回强连通分支结点数 */
        }
    } while (size);

    /* successfull end algorightm  */
    return g->V;
}
