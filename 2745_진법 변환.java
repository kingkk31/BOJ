import java.util.*;
import java.math.*;

public class Main {// BOJ
	
	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String n = in.next();
		int b = in.nextInt(), sum = 0;
		
		for(int i=0;i<n.length();i++)
		{
			char c = n.charAt(i);
			int temp;
			
			if('A' <= c && 'Z' >= c)
				temp = (int)(c - 'A' + 10);
			else
				temp = (int)(c - '0');
			
			sum += (temp * Math.pow(b, n.length() - 1 - i));
		}
		
		System.out.println(sum);
	}
}