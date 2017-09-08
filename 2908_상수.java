import java.util.*;
import java.math.*;

public class Main {// BOJ
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner in = new Scanner(System.in);
		String a,b;
		int num1, num2;
		
		a = in.next();
		b = in.next();
		
		a = new StringBuffer(a).reverse().toString();
		b = new StringBuffer(b).reverse().toString();
		
		num1 = Integer.parseInt(a);
		num2 = Integer.parseInt(b);
		
		System.out.printf("%d\n", num1 > num2 ? num1 : num2);
		
		in.close();
	}
}