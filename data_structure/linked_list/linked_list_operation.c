
/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*interface implementation*/

/*
 Takes a list and a data value.
 Creates a new link with the given data and pushes
 it onto the front of the list.
 The list is not passed in by its head pointer.
 Instead the list is passed in as a "reference" pointer
 to the head pointer -- this allows us
 to modify the caller's memory.
*/
//这是在前面添加！
void Push(struct node** headRef, int data) {
   struct node* newNode = malloc(sizeof(struct node));
   newNode->data = data;
   newNode->next = *headRef;  // The '*' to dereferences back to the real head
   *headRef = newNode;        // ditto
}
void PushTest() {
   struct node* head = BuildTwoThree();// suppose this returns the list {2, 3}
   Push(&head, 1);      // note the &
   Push(&head, 13);
   // head is now the list {13, 1, 2, 3}
}

// Return the number of nodes in a list (while-loop version)
int Length(struct node* head) {
   int count = 0;
   struct node* current = head;
   while (current != NULL) {
      count++;
      current = current->next
   }
   return(count);
}


struct node* AppendNode(struct node** headRef, int num) {
   struct node* current = *headRef;
   struct node* newNode;
   newNode = malloc(sizeof(struct node));
   newNode->data = num;
   newNode->next = NULL;
   // special case for length 0
   if (current == NULL) {
      *headRef = newNode;
   }
   else {
      // Locate the last node
      while (current->next != NULL) {
         current = current->next;
      }
      current->next = newNode;
   }
}


//这是在后面添加
struct node* AppendNode(struct node** headRef, int num) {
   struct node* current = *headRef;
   // special case for the empty list
   if (current == NULL) {
      Push(headRef, num);
   } else {
      // Locate the last node
      while (current->next != NULL) {
         current = current->next;
      }
      // Build the node after the last node
      Push(&(current->next), num);
   }
￼￼}
struct node* CopyList(struct node* head) {
   struct node* current = head;     // used to iterate over the original list
   struct node* newList = NULL;     // head of the new list
   struct node* tail = NULL;  // kept pointing to the last node in the new list
   while (current != NULL) {
      if (newList == NULL) {  // special case for the first new node
         newList = malloc(sizeof(struct node));
         newList->data = current->data;
         newList->next = NULL;
         tail = newList;
} else {
         tail->next = malloc(sizeof(struct node));
         tail = tail->next;
         tail->data = current->data;
         tail->next = NULL;
}
      current = current->next;
   }
   return(newList);
}
// Variant of CopyList() that uses Push()
struct node* CopyList2(struct node* head) {
   struct node* current = head;     // used to iterate over the original list
   struct node* newList = NULL;     // head of the new list
   struct node* tail = NULL;  // kept pointing to the last node in the new list
   while (current != NULL) {
      if (newList == NULL) {  // special case for the first new node
         Push(&newList, current->data);
         tail = newList;
      }
      else {
         Push(&(tail->next), current->data);    // add each node at the tail
         tail = tail->next;   // advance the tail to the new last node
}
      current = current->next;
   }
   return(newList);
}

// Local reference variant
struct node* CopyList(struct node* head) {
   struct node* current = head;     // used to iterate over the original list
   struct node* newList = NULL;
   struct node** lastPtr;
   lastPtr = &newList;        // start off pointing to the head itself
   while (current != NULL) {
      Push(lastPtr, current->data);
      lastPtr = &((*lastPtr)->next);
      current = current->next;
}
   return(newList);
}
// Recursive variant
struct node* CopyList(struct node* head) {
   if (head == NULL) return NULL;
   else {
      struct node* newList = malloc(sizeof(struct node));
      newList->data = current->data;
// make the one node
      newList->next = CopyList(current->next);  // recur for the rest
      return(newList);
   }
}


/*client*/
int main() {
	int *n=malloc(n*sizeof(int));
	if(n==NULL) {
		printf("n 没有分配到内存\n");
	}

	free(n);
	return 0;
}
