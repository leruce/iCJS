package iProlog;

import java.util.Scanner;

public class randomGenerator {
	
	Scanner scan = new Scanner(System.in);
	
	
	public randomGenerator() {
		// TODO Auto-generated constructor stub
	}
	
	public int[] randomGen()
	{
	    int[] result = new int[10];
	    int a = 17;
	    int X = 1;
	    int seed ;
	    System.out.println("\nEnter a prime number as seed(make sure it's same as you used in c++ testing to get same output): ");
	    seed = scan.nextInt();


	    for(int i=0; i<10; i++)
	    {
	        X = (a * X + seed) % 256;
	        result[i] =X%9;
	    }
	    return result;
	}

}



