
/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*interface implementation*/
struct node {
    int data;
    struct node*   next;
};

/*
 Build the list {1, 2, 3} in the heap and store
 its head pointer in a local stack variable.
 Returns the head pointer to the caller.
*/
struct node* BuildOneTwoThree() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));
// allocate 3 nodes in the heap
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    // setup first node
// note: pointer assignment rule
    // setup second node
    // setup third link
    // At this point, the linked list referenced by "head"
    // matches the list in the drawing.
    return head;
}

/*
 *  Given a linked list head pointer, compute
 *   and return the number of nodes in the list.
 *   */
int Length(struct node* head) {
    struct node* current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
void LinkTest() {
    struct node* head = BuildTwoThree(); // suppose this builds the {2, 3} list
    struct node* newNode;
    newNode= malloc(sizeof(struct node));  // allocate
    newNode->data = 1;
    newNode->next = head;                        // link next
    head = newNode;                              // link head
    //这是往前面加，最快！往后面加你需要遍历到最后一个元素！
    // now head points to the list {1, 2, 3}
}

/*client*/
int main() {
    struct node* head = NULL;
    head=BuildOneTwoThree();
    while(head!=NULL) {
        printf(" %d",head->data);
        head=head->next;
    }
    printf("\n");

    head=BuildOneTwoThree();
    printf("length is %d\n",Length(head));
    /*
    int *n=malloc(n*sizeof(int));
    if(n==NULL) {
        printf("n 没有分配到内存\n");
    }

    free(n);
    */
    return 0;
}
