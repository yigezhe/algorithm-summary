
#ifndef _PAIRHEAP_H
#define _PAIRHEAP_H

#include"base.h"

typedef struct phnode {
	Item item;
	struct phnode *left, *previous, *nextSibling;
} PHNode;

typedef struct pairingHeap {
	PHNode *root;
	int current;
} *PairingHeap;

/*创建并初始化配对堆*/
BOOL Initialize_P(PairingHeap * const pph);

/*确定一个配对堆是否为空*/
BOOL IsEmpty_P(const PairingHeap * const pph);

/*向配对堆中插入一个数据为指定数据的结点.localizer用来传递回新节点的地址*/
BOOL Insert_P(const PairingHeap * const pph, const Item item);

/*在配对堆上查找数据点*/
PHNode* Find_P(const PairingHeap * const pph, const Item item);

/*将配对堆中指定节点的数据降低delta*/
BOOL DecreaseKey_P(const PairingHeap * const pph, PHNode * const position,
		const ValueType delta);

/*删除配对堆中数据域最小的节点，并通过pmin将其携带回调用该函数的函数*/
BOOL DeleteMin_P(const PairingHeap * const pph, Item * const pmin);

/*打印堆*/
void Print_P(const PairingHeap * const pph);

/*释放配对堆占用的空间*/
void Release_P(PairingHeap * const pph);

#endif
