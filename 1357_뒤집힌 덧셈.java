import java.util.*;
import java.math.*;

public class Main {// BOJ
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner in = new Scanner(System.in);
		
		String num1, num2;
		num1 = in.next();
		num2 = in.next();
		num1 = new StringBuffer(num1).reverse().toString();
		num2 = new StringBuffer(num2).reverse().toString();
		
		int num3 = Integer.parseInt(num1) + Integer.parseInt(num2);
		num3 = Integer.parseInt(new StringBuffer(String.valueOf(num3)).reverse().toString());
		System.out.println(num3);
		
		in.close();
	}
}