/* Garrett Addington
Element in list are: [3, 2, 2, 4, 7, 7, 4, 7, 7, 8]
Element in list are: [2, 3]
Head is: 4
Tail is: [1, 0, 2, 2, 4, 0, 3, 4, 3]
*/
package iProlog;

import static org.junit.Assert.*;

import java.util.Arrays;

import org.junit.Before;
import org.junit.Test;


public class IntListTest {

	@Test
	public void testCons() {
		int[] hold = randomGen(13);
		//System.out.println(Arrays.toString(hold));
		IntList L1 = IntList.empty;
		IntList L2 = IntList.cons(hold[0], L1);
		IntList L3 = IntList.cons(hold[1], L2);
		System.out.println("Element in list are: "+ L3.toString());
	}
	@Test
	public void testApp() {
		int[] hold = randomGen(13);
		//System.out.println(Arrays.toString(hold));
		IntList L1 = IntList.empty;
		int[]  a = hold;
		IntList L2 = IntList.app(a, L1);
		System.out.println("Element in list are: "+ L2.toString());	
	}
	@Test
	public void testHead() {
		int[] hold = randomGen(113);
		//System.out.println(Arrays.toString(hold));
		IntList L1 = IntList.empty;
		int[]  a = hold;
		IntList L2 = IntList.app(a, L1);
		System.out.println("Head is: " + IntList.head(L2));
		System.out.println("Tail is: " + (IntList.tail(L2)).toString());
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

/*
Element in list are: [3, 2, 2, 4, 7, 7, 4, 7, 7, 8]
Element in list are: [2, 3]
Head is: 4
Tail is: [1, 0, 2, 2, 4, 0, 3, 4, 3]
*/
