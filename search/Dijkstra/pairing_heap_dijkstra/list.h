#ifndef _LIST_H
#define _LIST_H

#include"base.h"

/*单向链表节点*/
typedef struct ltnode {
	Item item;
	struct ltnode *next;
} LTNode;
/*单向链表定义*/
typedef struct linkedList {
	LTNode *head;
	int size;
} *LinkedList;

/*创建并初始化单向链表*/
BOOL Initialize_L(LinkedList * const llh);

/*确定一个单向链表是否为空*/
BOOL IsEmpty_L(const LinkedList * const llh);

/*向单向链表末尾添加一个元素*/
BOOL Insert_L(const LinkedList * const lln, const Item item);

/*释放单向链表占用的空间*/
void Release_L(LinkedList * const llh);

#endif
