#define MAXSIZE 500
int uset[MAXSIZE];
int rank[MAXSIZE];

void makeSet(int size) {
    for(int i = 0; i < size; i++)  uset[i] = i;
    for(int i = 0; i < size; i++)  rank[i] = 0;
}
int find(int x) {
    int p = x, t;
    while (uset[p] != p) p = uset[p];//这里一直循环下去
    //直到p=uset[p];
    while (x != p) {
        //这里为什么要做一个交换？
        t = uset[x];
        uset[x] = p;//x直接指向p
        x = t;//x的父节点也要指向p
    }
    //这里x还是变为了p
    //return x;
    return p;
}
void unionSet(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return;
    if (rank[x] > rank[y]) uset[y] = x;
    else {
        uset[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
    }
}
