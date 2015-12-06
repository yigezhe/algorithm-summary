#include"list.h"

static LTNode *makeNode(const Item item) {
    LTNode *newNode;
    newNode = (LTNode *) malloc(sizeof(struct ltnode));
    newNode->item = item;
    newNode->next = NULL;
    return newNode;
}

static void releaseNode(LTNode * const p) {
    if (p != NULL) {
        releaseNode(p->next);
        free(p);
    }
}

/*创建并初始化单向链表*/
BOOL Initialize_L(LinkedList * const llh) {
    (*llh) = (struct linkedList *) malloc(sizeof(struct linkedList));
    (*llh)->head = NULL;
    (*llh)->size = 0;
    return TRUE;
}

/*确定一个单向链表是否为空*/
BOOL IsEmpty_L(const LinkedList * const llh) {
    if ((*llh)->size == 0)
        return TRUE;
    else
        return FALSE;
}

/*向单向链表头部添加一个元素*/
BOOL Insert_L(const LinkedList * const llh, const Item item) {
    LTNode *newNode = makeNode(item);
    if ((*llh)->size == 0)
        (*llh)->head = newNode;
    else {
        newNode->next = (*llh)->head;
        (*llh)->head = newNode;
    }
    (*llh)->size++;
    return TRUE;
}

/*释放单向链表占用的空间*/
void Release_L(LinkedList * const llh) {
    releaseNode((*llh)->head);
    free(*llh);
}

