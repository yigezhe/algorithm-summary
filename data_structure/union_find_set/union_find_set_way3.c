//learn from
//http://www.cnblogs.com/cyjb/p/UnionFindSets.html
#define MAXSIZE 500
int uset[MAXSIZE];

//这样的并查集具有一个略微不同的定义，即若 uset 的值是正数，则表示该元素的父节点（的索引）；若是负数，则表示该元素是所在集合的代表（即树根），而且值的相反数即为集合中的元素个数。相应的代码如下所示，同样包含递归和非递归的 find 操作：
void makeSet(int size) {
    for(int i = 0; i < size; i++) uset[i] = -1;
}
int find(int x) {
    if (uset[x] < 0) return x;
    uset[x] = find(uset[x]);
    return uset[x];
}
int find(int x) {
    int p = x, t;
    while (uset[p] >= 0) p = uset[p];
    while (x != p) {
        t = uset[x];
        uset[x] = p;
        x = t;
    }
    return x;
}
//并查集还有一种常见的策略，就是按集合中包含的元素个数（或者说树中的节点数）合并，将包含节点较少的树根，指向包含节点较多的树根。这个策略与按秩合并的策略类似，同样可以提升并查集的运行速度，而且省去了额外的 rank 数组。
void unionSet(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return;
    if (uset[x] < uset[y]) {
        uset[x] += uset[y];
        uset[y] = x;
    } else {
        uset[y] += uset[x];
        uset[x] = y;
    }
}
//如果要获取某个元素 x 所在集合包含的元素个数，可以使用 -uset[find(x)] 得到。
