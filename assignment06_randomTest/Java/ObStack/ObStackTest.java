
/* 
 MD Khorrom Khan
 
 */


package iProlog;

import org.junit.Test;

public class ObStackTest {

	public static ObStack o = new ObStack();
	public static randomGenerator rg = new randomGenerator();
	int[] holder = rg.randomGen();
	
	
	@Test
	public void testPush() {
		System.out.println("\n\nTesting push........");
		if (o.isEmpty()) {
			System.out.println("Initially the stack size is: "+ (o.size()));
		}else {
			for (int i=0; i<10; i++) {
				Object j = o.pop();
			}
			System.out.println("Initially the stack size is: " +(o.size()));
		}
		
		for (int i=0; i<10; i++) {
		o.push(holder[i]);
		System.out.println(o.get(o.size()-1)+" is pushed to the stack and stack size increased to: "+(o.size()));
		}
	}

	@Test
	public void testPop() {
		System.out.println("\nTesting pop......");
		System.out.println("First we pushed 10 numbers into the stack.");
		for (int i=0; i<10; i++) {
			o.push(holder[i]);
		}
		for (int i=0; i<10; i++) {
			Object j = o.pop();
			System.out.println(j.toString()+" is popped from the stack.");
		}
	}
	@Test
	public void testPeek() {
		System.out.println("\n\nTesting peep......");
		for (int i=0; i<10; i++) {
			o.push(holder[i]);
		}
		System.out.println("First we pushed 10 numbers into the stack and "+holder[9]+" is at the top of the stack.");
		
			Object j = o.peek();
			System.out.println("We peep on the stack: "+ j + "\n");
		}
}

/* -- - -- - - - -- - -- - -- - -- - -- - SAMPLE OUTPUT - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - -- - --
Enter a prime number as seed(make sure it's same as you used in c++ testing to get same output): 
11

Testing pop......
First we pushed 10 numbers into the stack.
3 is popped from the stack.
0 is popped from the stack.
7 is popped from the stack.
1 is popped from the stack.
0 is popped from the stack.
5 is popped from the stack.
6 is popped from the stack.
8 is popped from the stack.
6 is popped from the stack.
1 is popped from the stack.

Enter a prime number as seed(make sure it's same as you used in c++ testing to get same output): 
13


Testing peep......
First we pushed 10 numbers into the stack and 8 is at the top of the stack.
We peep on the stack: 8


Enter a prime number as seed(make sure it's same as you used in c++ testing to get same output): 
17


Testing push........
Initially the stack size is: 0
7 is pushed to the stack and stack size increased to: 1
2 is pushed to the stack and stack size increased to: 2
4 is pushed to the stack and stack size increased to: 3
4 is pushed to the stack and stack size increased to: 4
7 is pushed to the stack and stack size increased to: 5
3 is pushed to the stack and stack size increased to: 6
2 is pushed to the stack and stack size increased to: 7
3 is pushed to the stack and stack size increased to: 8
7 is pushed to the stack and stack size increased to: 9
0 is pushed to the stack and stack size increased to: 10
*/
