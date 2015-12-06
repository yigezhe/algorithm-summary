import java.util.LinkedList;  

public class Stack<E>{
	LinkedList<E> list;

	public Stack(){
		list = new LinkedList();
	}

	public E pop(){
		return list.removeLast();
	}

	public void push(E o){
		list.add(o);
	}

	public E getTop(){
		return list.getLast();
	}

	public boolean isEmpty(){
		return list.size()==0;
	}

	public int size(){
		return list.size();
	}

	public static void main(String[] args) {
		Stack stack = new Stack();
		stack.push("bottom");
		stack.push("middle");
		stack.push("top");
		System.out.println(stack.isEmpty());
		System.out.println(stack.getTop());
		System.out.println(stack.pop());
		System.out.println(stack.pop());
		System.out.println(stack.pop());
		System.out.println(stack.isEmpty());
	}

}
