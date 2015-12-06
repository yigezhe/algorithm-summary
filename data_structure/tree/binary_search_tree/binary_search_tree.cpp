/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*interface implementation*/
struct node {
    int val;//value
    node *lch,*rch;//left child,right child
};
void print(node *p) {
    if(p==NULL) {
        printf("这是一个空节点\n");
        return;
    } else {
        if(p->lch!=NULL && p->rch!=NULL) {
            printf("%d的两个子节点是(%d,%d)\n",p->val,p->lch->val,p->rch->val);
        } else if(p->lch!=NULL) {
            printf("%d的一个左子节点是%d\n",p->val,p->lch->val);
        } else if(p->rch!=NULL) {
            printf("%d的一个右子节点是%d\n",p->val,p->rch->val);
        } else {
            printf("%d无左右子节点\n",p->val);
        }
    }
    if(p->lch!=NULL) {
        print(p->lch);
    }
    if(p->rch!=NULL) {
        print(p->rch);
    }
}
node * insert(node *p,int x) {
    if(p==NULL) {
        node *q=new node;
        q->val=x;
        q->lch=q->rch=NULL;
        return q;
    } else {
        if(x<p->val)
            p->lch=insert(p->lch,x);
        //对左支做了一个更新！
        else
            p->rch=insert(p->rch,x);
        //对右支做了一个更新！
        return p;
    }
}
bool find(node *p,int x) {
    if(p==NULL) return false;
    else if(x==p->val) return true;
    //小的话，在左支上找！
    else if(x<p->val) return find(p->lch,x);
    else return find(p->rch,x);
}
node *remove(node *p,int x) {
	//空的不用删除！
    if(p==NULL) return NULL;
    //从左支去删除！
    else if(x<p->val) p->lch=remove(p->lch,x);
    //从右支去删除！
    else if(x>p->val) p->rch=remove(p->rch,x);
    //下面的情况是已经找到了要删除的元素！
    else if(p->lch==NULL) {
	    //要删除的元素没有左支！
        node *q=p->rch;//保存整个右支！
        delete p;//为什么要删除p？
        return q;//返回已经保存的右支？
    } else if(p->lch->rch==NULL) {
	    //有左儿子，但左儿子没有右儿子
        node *q=p->lch;//保存左儿子，左儿子的左支不变，右支变为被删除元素的右支！
        q->rch=p->rch;
        delete p;
        return q;
    } else {
        node *q;
	//寻找左儿子的所有右子孙中的最后一个
	//因为这个就是左儿子的子孙中最大的！
        for(q=p->lch; q->rch->rch!=NULL; q=q->rch);
        node *r=q->rch;
	//我们找到的最后一个节点还可能多出一个左支！
        q->rch=r->lch;//把要调上去的节点的左支，交给他的父亲，放在父亲的右支下面！
        r->lch=p->lch;//调上去的节点接管要删除节点的左右支！
	//太厉害了！
        r->rch=p->rch;
        delete p;
        return r;
    }
    return p;
}
//删除以node为根节点的树
//以递归的形式删除
void deleteTree(node * p) {
    if(p == NULL) return;

    if(p->lch != NULL) {
        deleteTree(p->lch);
    }

    if(p->rch != NULL) {
        deleteTree(p->rch);
    }

    if(p->lch == NULL && p->rch == NULL) {
        free(p);
        p = NULL;
    }
}
/*client*/
int main() {
    node *root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,5);
    root=insert(root,4);
    root=insert(root,7);
    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,8);
    root=insert(root,11);
    root=insert(root,17);
    root=insert(root,16);
    root=insert(root,19);
    printf("\n------------\n");
    print(root);
    root=insert(root,6);
    printf("\n------------\n");
    print(root);

    root=remove(root,15);
    printf("\n------------\n");
    print(root);


    //find(root,1);
    //我的发现是：插入顺序不同，得到的树的结构也是不同的！
    return 0;
}
