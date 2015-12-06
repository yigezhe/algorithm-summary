//http://blog.csdn.net/stevemarbo/article/details/7292679
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
struct node {
    int data;
    struct node* next;
};
struct node* BuildOneTwoThreeFourFive() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    struct node* forth = NULL;
    struct node* fifth = NULL;

    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));
    forth = malloc(sizeof(struct node));
    fifth = malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = forth;

    forth->data = 4;
    forth->next = fifth;

    fifth->data = 5;
    fifth->next= NULL;
    return head;
}
int Length(struct node* head) {
    struct node* current = head;
    int count = 0;

    while(current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}
void Push(struct node** headRef, int data) {
    struct node* newNode = malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

int GetNth(struct node* head, int index) {
    struct node* current = head;
    int count = 0;

    while(current != NULL) {
        if(count == index) return (current->data);
        count++;
        current = current->next;
    }

    assert(0);
}
void DeleteList(struct node** headRef) {
    struct node* current = *headRef;
    struct node* next;

    while(current != NULL) {

        next = current->next;
        free(current);
        current = next;
    }

    *headRef = NULL;
}
int Pop(struct node** headRef) {
    struct node* head;
    int result;

    head = *headRef;

    assert(head != NULL);

    result = head->data;
    *headRef = head->next;

    free(head);
    return result;
}
int main() {
    struct node *start;
    start=BuildOneTwoThreeFourFive() ;
    printf("start length is %d\n",Length(start));
    Push(&start,6);
    printf("start length is %d\n",Length(start));
    int i;
    for(i=0; i<6; i++) {
        printf(" %d",GetNth(start, i));
    }
    printf("\n");
    Pop(&start);
    printf("start length is %d\n",Length(start));
    for(i=0; i<5; i++) {
        printf(" %d",GetNth(start, i));
    }
    printf("\n");

    Pop(&start);
    printf("start length is %d\n",Length(start));
    for(i=0; i<4; i++) {
        printf(" %d",GetNth(start, i));
    }
    printf("\n");


    return 0;
}
