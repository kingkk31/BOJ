import java.util.*;
import java.math.*;

public class Main {// BOJ
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int n, m;
		BigInteger a = BigInteger.valueOf(1), b = BigInteger.valueOf(1);
		
		n = in.nextInt();
		in.nextLine();
		StringTokenizer st = new StringTokenizer(in.nextLine());
		for(int i=0;i<n;i++)
			a = a.multiply(new BigInteger(st.nextToken()));
		
		m = in.nextInt();
		in.nextLine();
		st = new StringTokenizer(in.nextLine());
		for(int i=0;i<m;i++)
			b = b.multiply(new BigInteger(st.nextToken()));
		
		String ans = a.gcd(b).toString();
		if(ans.length() > 9)
			System.out.println(ans.substring(ans.length() - 9));
		else
			System.out.println(ans);
	}
}