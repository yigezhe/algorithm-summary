/*（1）Dijkstra算法解决了有向图上带权的单元最短路径问题，但是算法要求所有的权值必须是非负。算法的思想及其实现均参考《算法导论》一书。

Dijkstra算法的时间复杂度依赖于最小优先队列的具体实现，下述算法采用的是最小堆结构，时间复杂度为O((V+E)lgV)
（2）算法实现：（简单案例测试成功，若存在问题请指出，多谢。）
*/
#include <iostream>
using namespace std;


#define MAX_NODE 1000
#define INFINITY 9999999
#define NIL -1
typedef struct ArcNode  {
    int adjvex;
//弧指向的节点的值（点的标号）  int distance;
//两点之间的距离 int weight;
//边的权重 ArcNode* next;
//指向下一条弧  ArcNode(int value)  {  adjvex = value;
    next = NULL;
}
};
//邻接表节点   typedef struct  {  int vexdata;
//头节点的标号  struct ArcNode* firstarc;
//第一个邻接表节点的地址  }
VexNode, AdjList[MAX_NODE];
//头结点   typedef struct  {  AdjList vexNodes;
int vexNum;
int arcNum;
//当前节点数目和弧数  }
GraphWithAL;
//邻接表表示的图   //检测要输入的边是否已经存在，针对无向图  bool CheckArcIsExist(GraphWithAL* G, int v1, int v2)  {  ArcNode* temp = G->vexNodes[v1].firstarc;
while(temp!=NULL)  {
    if(temp->adjvex == v2)  return true;
    temp = temp->next;
}
return false;
}
//创建图，vexNum代表顶点的个数，arcNum代表边的个数，isUnDirected代表的是 是否是无向图  void CreateGraph(GraphWithAL* G, int vexNum, int arcNum)  {  memset(G, 0 ,sizeof(GraphWithAL));
//初始化头结点  int i = 0;
for(i=0;
        i<vexNum;
        ++i)  {
    G->vexNum = vexNum;
    G->vexNodes[i].firstarc = NULL;
    G->vexNodes[i].vexdata = i;
//从0开始计算顶点  }
    //初始化边  for(i=0;
    i<arcNum;
    ++i)  {  //输入边的顶点和尾点  int v1, v2, weight;
        cin>>v1>>v2>>weight;
        if(CheckArcIsExist(G, v1, v2))  continue;
        ArcNode* arcNode = new ArcNode(v2);
        //还需要检验边是否已经存在，这里没有检验  arcNode->next = G->vexNodes[v1].firstarc;
        arcNode->weight= weight;
        G->vexNodes[v1].firstarc = arcNode;
        G->arcNum++;
    }
}
//初始化d[]，保存从源点到各个顶点的最短路径距离，num代码节点数目 void InitialSingleSource(int s, int d[], int pi[], int num) { int i=0;
for(;
        i<num;
        ++i) {
    d[i] = INFINITY;
    pi[i] = NIL;
}
d[s] = 0;
}
//松弛技术 void Relax(int u, int v, int weight, int d[], int pi[]) { if(d[v] > d[u]+weight) { d[v] = d[u] +weight;
pi[v] = u;
}
}
//修整最小堆 ,使用最小堆结构存储d[]的下标值，目的是最快的方式取出d[]中的最小值下标 void fix_min_heap(int a[], int pos, int len, int d[]) {  int left = 2 * pos + 1;
int right = 2 * pos + 2;
int min = pos;
if (left < len && d[a[left]] < d[a[pos]])  min = left;
if (right < len && d[a[right]] < d[a[min]])  min = right;
if (pos != min) {
    int tep = a[pos];
    a[pos] = a[min];
    a[min] = tep;
    fix_min_heap(a, min, len, d);
}
}
//建立最小堆  void build_min_heap(int a[], int len, int d[]) {  int parent = (len - 1) / 2;
int i = 0, j = 0;
for (i = parent;
        i >= 0;
        --i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int min = i;
    if (left < len && d[a[left]] < d[a[i]])  min = left;
    if (right < len && d[a[right]] < d[a[min]])  min = right;
    if (i != min) {
        int tep = a[i];
        a[i] = a[min];
        a[min] = tep;
        fix_min_heap(a, min, len, d);
    }
}
}
//去出最小堆的最小值 int ExtractMin(int a[], int n, int d[]) { int temp = a[0];
a[0] = a[n-1];
fix_min_heap(a, 0, n-1, d);
return temp;
}
void Dijkstra(GraphWithAL* G, int s) {
    int* d = new int[G->vexNum];
//记录每个顶点距源点的最小距离 int* pi = new int[G->vexNum];
    int* a = new int[G->vexNum];
//记录最小距离d的下标值 int i=0;
    for(i=0; i<G->vexNum; ++i)//初始化a a[i] = i;
        InitialSingleSource(s, d, pi, G->vexNum);
    int num = G->vexNum;
//起初最小堆中的值为顶点的数量，  while(num != 0) { int min = ExtractMin(a, num--, d);
    ArcNode* temp = G->vexNodes[min].firstarc;
    while(temp != NULL) {
        Relax(min, temp->adjvex, temp->weight, d, pi);
        temp = temp->next;
    }
}
for(i=0;
        i<G->vexNum;
        ++i) cout<<d[i]<<" ";
cout<<endl;
}
int main()  {
    GraphWithAL G;
    int n, m;
    while(cin>>n>>m)  {
        if(n==0)  break;
        CreateGraph(&G, n, m);
        Dijkstra(&G, 1);
    }
    return 0;
}
