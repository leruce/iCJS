package iProlog;

import static org.junit.Assert.*;

import org.junit.Test;

public class ObStackTest {
	
	public static ObStack o = new ObStack();
	
	@Test
	public void testPush() {
		System.out.println("Testing push........");
		if (o.isEmpty()) {
			System.out.println("Initially the stack size is: "+o.size());
		}else {
			System.out.println("Current stack size is: "+o.size());
		}
		o.push(12);
		System.out.println(o.get(o.size()-1)+" is pushed to the stack and stack size increased to: "+o.size());
	}
	
	@Test
	public void testPop() {
		System.out.println("Testing pop......");
		System.out.println("First we pushed 10 into the stack.");
		o.push(10);
		Object j = o.pop();
		System.out.println(j.toString()+" is popped from the stack.\n");
	}
}
