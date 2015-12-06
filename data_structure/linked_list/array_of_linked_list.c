
/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node {
    int data;
    struct node*   next;
};

/*client*/
int main() {

    //Just make it like any other array:
    //c Syntax (Toggle Plain Text)
    //struct songlist* array[const_size];
    struct node* array[3];

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
    struct node* current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        printf("%d: %d\n",count,current->data);
        current = current->next;
    }
    struct node* newNode;
    newNode= malloc(sizeof(struct node));  // allocate
    newNode->data = 8;
    newNode->next = head;                        // link next
    head = newNode;                              // link head

    current = head;
    count = 0;
    while (current != NULL) {
        count++;
        printf("%d: %d\n",count,current->data);
        current = current->next;
    }
    array[0]=head;
    array[1]=second;
    array[2]=third;
    int i;
    for(i=0; i<3; i++) {
        current=array[i];
        count = 0;
        while (current != NULL) {
            count++;
            printf("%d: %d--",count,current->data);
            current = current->next;
        }
        printf("\n");

    }
    //这是往前面加，最快！往后面加你需要遍历到最后一个元素！
    // now head points to the list {1, 2, 3}
    // setup first node
// note: pointer assignment rule
    // setup second node
    // setup third link
    // At this point, the linked list referenced by "head"
    // matches the list in the drawing.
    return 0;
}
