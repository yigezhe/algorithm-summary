#include"pairheap.h"

/*全局变量声明*/
static PHNode *NullNode = NULL;

/*局部函数声明*/
static PHNode *compareAndLink_P(PHNode * const first, PHNode * const second);
static PHNode *makeNode_P(const Item item);
static PHNode *combineSiblings_P(PHNode * firstSibling);
static void release_P(PHNode * const pn);
static PHNode *find(PHNode * const root, const Item item);
static void printNode(const PHNode * const root);

/*局部函数定义*/
static PHNode *compareAndLink_P(PHNode * const first, PHNode * const second) {
    if (second == NullNode)
        return first;
    if (second->item.dist < first->item.dist) {    /*把first作为second的最左子孩子 */
        second->previous = first->previous;
        first->previous = second;
        first->nextSibling = second->left;
        first->nextSibling->previous = first;
        second->left = first;
        return second;
    } else {        /*把second作为first的最左孩子 */
        second->previous = first;
        first->nextSibling = second->nextSibling;
        first->nextSibling->previous = first;
        second->nextSibling = first->left;
        second->nextSibling->previous = second;
        first->left = second;
        return first;
    }
}

static PHNode *makeNode_P(const Item item) {
    PHNode *newNode;
    newNode = (PHNode *) malloc(sizeof(PHNode));
    if (NULL == newNode)
        return NULL;
    newNode->item = item;
    newNode->left = newNode->nextSibling = newNode->previous = NullNode;
    return newNode;
}

static PHNode *combineSiblings_P(PHNode * firstSibling) {
    static PHNode *treeArray[MAXSIBLINGS];  /*treeArray是个一维数组，每个元素是Node*类型。静态成员在编译时就要初始化，所以数组长度必须是已知的。给treeArray分配一个足够大的长度，再定义为静态的（全局生命周期），每次调用函数时都使用这一个treeArray，省去过多的重复初始化 */
    int i, j, numSiblings;
    /*如果只有一个孩子，则直接返回它 */
    if (firstSibling->nextSibling == NullNode)
        return firstSibling;
    /*把所有兄弟放在treeArray中 */
    for (numSiblings = 0; firstSibling != NullNode; numSiblings++) {
        treeArray[numSiblings] = firstSibling;
        /*打断双向链表中每个节点向后的指针 */
        firstSibling->previous->nextSibling = NullNode;
        firstSibling = firstSibling->nextSibling;
    }
    treeArray[numSiblings] = NullNode;  //一定要把最后一个设为NullNode，因为treeArray的总长度为MAXSIBLINGS，NullNode之前的才是有效元素
    /*从左向右两两合并子树 */
    //printf("第一趟合并： ");
    for (i = 0; i + 1 < numSiblings; i += 2) {
        treeArray[i] = compareAndLink_P(treeArray[i], treeArray[i + 1]);
        //printf("一次");
        //printNode(treeArray[i]);
    }
    j = i - 2;
    if (j == numSiblings - 3) { /*兄弟有奇数个 */
        treeArray[j] = compareAndLink_P(treeArray[j], treeArray[j + 2]);
        //printf("合并最一个奇数项");
        //printNode(treeArray[j]);
    }
    /*进行第二趟合并 */
    /*从右向左逐个合并 */
    //printf("第二趟合并： ");
    while (j >= 2) {
        treeArray[j - 2] =
            compareAndLink_P(treeArray[j - 2], treeArray[j]);
        //printf("一次");
        //printNode(treeArray[j-2]);
        j -= 2;
    }
    return treeArray[0];
}

static void release_P(PHNode * const pn) {
    if (pn != NullNode) {
        release_P(pn->left);
        release_P(pn->nextSibling);
        free(pn);
    }
}

static PHNode *find(PHNode * const root, const Item item) {
    //printf("开始查找vindex=%d\tdist=%d\n",root->item.vindex,(int)root->item.dist);
    if(root==NullNode)
        return NullNode;
    else if(root->item.vindex==item.vindex)
        return root;
    else if(item.dist<root->item.dist)
        return find(root->nextSibling,item);
    else {
        PHNode *rect;
        return ((rect=find(root->nextSibling,item))==NullNode)?find(root->left,item):rect;/*先搜兄弟节点;如果找不到，再搜孩子节点;如果还找不到则返回NullNode*/
    }
}

static void printNode(const PHNode * const root) {
    if(root==NullNode) {
        printf("\t");
        return;
    } else {
        printf("%d(%d)\t",root->item.vindex,(int)root->item.dist);
        printf("%d's next:",root->item.vindex);
        printNode(root->nextSibling);
        printf("%d's left:",root->item.vindex);
        printNode(root->left);
    }
}

/*************************************接口函数定义********************************/
BOOL Initialize_P(PairingHeap * const pph) {
    if (NullNode == NULL) {
        NullNode = (PHNode *) malloc(sizeof(PHNode));
        if (NullNode == NULL) {
            puts("Out of space.");
            return FALSE;
        }
        *pph = (struct pairingHeap *)malloc(sizeof(struct pairingHeap));
        if (*pph == NULL) {
            puts("Out of space");
            free(NullNode);
            NullNode == NULL;
            return FALSE;
        }
        NullNode->left = NullNode->previous = NullNode->nextSibling = NullNode;
        (*pph)->root = NullNode;
        (*pph)->current = 0;
    }
    return TRUE;
}

BOOL IsEmpty_P(const PairingHeap * const pph) {
    switch ((*pph)->current) {
    case 0:
        return TRUE;
    default:
        return FALSE;
    }
}

BOOL Insert_P(const PairingHeap * const pph, const Item item) {
    PHNode *newNode;
    newNode = makeNode_P(item);
    if (newNode == NULL) {
        puts("out of space.");
        return FALSE;
    }
    //*localizer = newNode;
    if (IsEmpty_P(pph) == TRUE)
        (*pph)->root = newNode;
    else
        (*pph)->root = compareAndLink_P((*pph)->root, newNode);
    (*pph)->current++;
    return TRUE;
}

PHNode *Find_P(const PairingHeap * const pph, const Item item) {
    //printf("调用Find_P\n");
    PHNode * rect=find((*pph)->root,item);
    if(rect==NullNode)
        return NULL;
    else {
        return rect;
    }
}

BOOL DecreaseKey_P(const PairingHeap * const pph, PHNode * const position,
                   const ValueType delta) {
    if (delta <= 0)
        return FALSE;
    //printf("要把%d降低%d\n",position->item.vindex,(int)delta);
    position->item.dist -= delta;
    //printf("降低节点值以后：vindex=%d\tdist=%d\n",position->item.vindex,(int)position->item.dist);
    if (position == (*pph)->root)
        return TRUE;    /*如果减小的是根节点的值，可以直接返回 */
    /*把position从堆上(双向链表中)取下来 */
    position->nextSibling->previous = position->previous;
    if (position->previous->left == position) /*position是最左孩子 */
        position->previous->left = position->nextSibling;
    else
        position->previous->nextSibling = position->nextSibling;
    position->nextSibling = NullNode;
    /*再把position合并到堆的根节点上去*/
    (*pph) -> root = compareAndLink_P ((*pph) -> root, position) ;
    return TRUE;
}

BOOL DeleteMin_P(const PairingHeap * pph, Item * const pmin) {
    PHNode *newRoot;
    if (IsEmpty_P(pph))
        return FALSE;
    else {
        newRoot = NullNode;
        *pmin = (*pph)->root->item;
        if ((*pph)->root->left != NullNode)
            newRoot = combineSiblings_P((*pph)->root->left);
        free((*pph)->root);
        (*pph)->root = newRoot;
        (*pph)->current--;
        return TRUE;
    }
}

void Print_P(const PairingHeap * const pph) {
    if((*pph)->root==NullNode)
        return;
    else
        printNode((*pph)->root);
    printf("\n");
}

void Release_P(PairingHeap * const pph) {
    release_P((*pph)->root);
    free(*pph);
    free(NullNode);
    NullNode = NULL;
}
