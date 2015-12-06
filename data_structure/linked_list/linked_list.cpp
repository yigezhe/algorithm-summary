//A typical linked list implementation would have code that defines a node, and looks something like this:

class ListNode {
	   String data;
	      ListNode nextNode;
}
ListNode firstNode;
//You could then write a method to add new nodes by inserting them at the beginning of the list:

ListNode newNode = new ListNode();
NewNode.nextNode = firstNode;
firstNode = newNode;

//Iterating through all of the items in the list is a simple task:

ListNode curNode = firstNode;
while (curNode != null) {
	   ProcessData(curNode);
	      curNode = curNode.nextNode;
}
