/* Garrett Addington
 * Output of unittest
s.size() : 3= 3
s.get(s.getTop) : 2= 2
s.pop() : 7= 7
s.getTop : 0= 0
 **/


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
	}
	@Test
	public void testPushStack() {
		int[] hold = randomGen(13);
		s.push(hold[1]);
		assertEquals(s.get(s.getTop()), hold[1]);
		out.println("s.get(s.getTop) : " + s.get(s.getTop()) + "= " + hold[1]);
	}
	
	@Test
	public void testPushStackTwice() {
		int[] hold = randomGen(113);
		s.push(hold[1]);
		s.push(hold[2]);
		assertEquals(s.get(s.getTop()), hold[2]);
		out.println("s.get(s.getTop) : " + s.get(s.getTop())  + "= " + hold[2]);
	}
	
	@Test
	public void testPopStack() {
		int[] hold = randomGen(13);
		s.push(hold[3]);
		s.push(hold[4]);
		int i = s.pop();
		assertEquals(i, hold[4]);
		out.println("s.pop() : " + i + "= " + hold[4]);
	}
	
	@Test
	public void testSize() {
		int[] hold = randomGen(13);
		s.push(hold[5]);
		s.push(hold[6]);
		s.push(hold[7]);
		assertEquals(s.size(), 3);
		out.println("s.size() : " + s.size() + "= 3");
	}
    public int[] randomGen(int seeder) {
        int[] result = new int[10];
        int a = 17;
        int X = 1;
        int seed ;
        //System.out.println("\nEnter a prime number as a seed(use same number in c++ testing too): ");
        seed = seeder;
        for(int i=0; i<10; i++)
        {
            X = (a * X + seed) % 256;
            result[i] =X%9;
        }
        return result;
    }

}

