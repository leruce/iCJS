
public class TestIntList {

	public static void main(String[] args) {
		
		
		IntList L1 = new IntList (1);
		IntList L2 = new IntList (2,L1);
		IntList L3 = new IntList (3,L2);
		
		System.out.println(L3);
		
	

    }
}
/*
Output =1, 2, 3
*/
