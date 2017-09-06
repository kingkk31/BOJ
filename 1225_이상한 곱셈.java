import java.util.*;
import java.math.*;

public class Main {// BOJ
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner in = new Scanner(System.in);
		String a = in.next();
		String b = in.next();
		
		BigInteger temp = new BigInteger("0");
		int lenA = a.length(), lenB = b.length();
		
		for(int i=0;i<lenA;i++)
			temp = temp.add(new BigInteger(""+a.charAt(i)));
		
		BigInteger num = new BigInteger("0");
		for(int i=0;i<lenB;i++)
			num = num.add(temp.multiply(new BigInteger(""+b.charAt(i))));

		System.out.println(num);
	}
}