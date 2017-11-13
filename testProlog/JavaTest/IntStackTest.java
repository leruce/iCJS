package iProlog;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;
import static java.lang.System.out;


public class IntStackTest {
	IntStack s;
	@Before
	public void setUp() throws Exception {
		s = new IntStack();
	}

	@Test
	public void testCreateStack() {
		assertEquals(s.getTop(), -1);
		out.println("s.getTop : " + s.getTop() + "= -1");
	}
	
	@Test
	public void testPushStack() {
		s.push(1);
		assertEquals(s.getTop(), 0);
		out.println("s.getTop : " + s.getTop() + "= 0");
	}
	
	@Test
	public void testPushStackTwice() {
		s.push(1);
		s.push(2);
		assertEquals(s.getTop(), 1);
		out.println("s.getTop : " + s.getTop() + "= 1");
	}
	
	@Test
	public void testPopStack() {
		s.push(12);
		s.push(10);
		int i = s.pop();
		assertEquals(i, 10);
		out.println("s.pop() : " + i + "= 10");
	}
	
	@Test
	public void testSize() {
		s.push(2);
		s.push(4);
		s.push(10);
		assertEquals(s.size(), 3);
		out.println("s.size() : " + s.size() + "= 3");
	}

}

/*
 * Output of unittest
s.getTop : -1= -1
s.size() : 3= 3
s.getTop : 0= 0
s.pop() : 10= 10
s.getTop : 1= 1
 
 **/
