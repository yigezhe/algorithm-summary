//https://zh.wikipedia.org/wiki/树_(数据结构)
/*树的孩子链表存储表示*/
typedef struct CTNode { // 孩子节点
  int child;
  struct CTNode *next;
} *ChildPtr;
typedef struct {
  ElemType data； // 节点的数据元素
  ChildPtr firstchild； // 孩子链表头指针
} CTBox;
typedef struct {
  CTBox nodes[MAX_TREE_SIZE]；
  int n, r； // 节点数和根节点的位置
} CTree;
/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
	return 0;
}
