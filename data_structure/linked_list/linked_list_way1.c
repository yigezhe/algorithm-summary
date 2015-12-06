
/*interface*/
/*interface implementation*/
/*client*/

#include <stdlib.h>

struct node {
    int x;
    struct node *next;
};

int main() {
    /* This will be the unchanging first node */
    struct node *root;

    /* Now root points to a node struct */
    root = (struct node *) malloc( sizeof(struct node) );

    /* The node root points to has its next pointer equal to a null pointer
     *        set */
    root->next = 0;
    /* By using the -> operator, you can modify what the node,
    *        a pointer, (root in this case) points to. */
    root->x = 5;
}
