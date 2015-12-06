
/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*interface implementation*/
struct node {
	int key;
	struct node *left;
	struct node *right;
	struct node *parent;
};
/*client*/
int main() {
	struct node * p=malloc(sizeof(struct node));
	if(p==NULL) {
		printf("p 没有申请到内存！\n");
	}
	p->key=1;
	p->left=NULL;
	p->right=NULL;
	p->parent=NULL;
    int n;
    scanf("%d",&n);
    int *a=malloc(n*sizeof(int));
    if(a==NULL) {
        printf("n 没有分配到内存\n");
    }
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }

    free(a);
    return 0;
}
