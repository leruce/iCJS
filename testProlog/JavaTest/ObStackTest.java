/*
Garrett Addington
This file  is suppose to be in the same location with the other soruce files when building
Testing pop......
First we pushed 10 into the stack.
10 is popped from the stack.

Testing peep......
We push 10 into the stack
We peep on the stack: 10

Testing push........
Current stack size is: 0
12 is pushed to the stack and stack size increased to: 1
*/

package iProlog;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class ObStackTest {

	public static ObStack o = new ObStack();

	@Test
	public void testPush() {
		System.out.println("Testing push........");
		if (o.isEmpty()) {
			System.out.println("Initially the stack size is: "+ (o.size() -1));
		}else {
			System.out.println("Initially the stack size is: " +(o.size() -1));
		}
		o.push(12);
		System.out.println(o.get(o.size()-1)+" is pushed to the stack and stack size increased to: "+(o.size() -1));
	}

	@Test
	public void testPop() {
		System.out.println("Testing pop......");
		System.out.println("First we pushed 10 into the stack.");
		o.push(10);
		Object j = o.pop();
		System.out.println(j.toString()+" is popped from the stack.\n");
	}
	@Test
	public void testPeek() {
		System.out.println("Testing peep......");
		System.out.println("We push 10 into the stack");
		o.push(10);
		Object j = o.peek();
		System.out.println("We peep on the stack: "+ j + "\n");
	}
}


/*
Testing pop......
First we pushed 10 into the stack.
10 is popped from the stack.

Testing peep......
We push 10 into the stack
We peep on the stack: 10

Testing push........
Current stack size is: 0
12 is pushed to the stack and stack size increased to: 1

*/
