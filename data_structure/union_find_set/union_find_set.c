#define MAXSIZE 500
int uset[MAXSIZE];
int rank[MAXSIZE];
 
void makeSet(int size) {
    for(int i = 0;i < size;i++)  uset[i] = i;
    for(int i = 0;i < size;i++)  rank[i] = 0;
}
int find(int x) {
	//如果每次都沿着父节点向上查找，那时间复杂度就是树的高度，完全不可能达到常数级。这里需要应用一种非常简单而有效的策略——路径压缩。
	//路径压缩，就是在每次查找时，令查找路径上的每个节点都直接指向根节点
    if (x != uset[x]) uset[x] = find(uset[x]);
    return uset[x];
}
void unionSet(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return;
    if (rank[x] > rank[y]) uset[y] = x;
    else {
        uset[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
    }
}
