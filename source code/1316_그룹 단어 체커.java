import java.util.*;
import java.math.*;

public class Main {// BOJ
	
	static boolean solve(String str)
	{
		int[] alphabet = new int[26];
		
		char pre = str.charAt(0);
		alphabet[(int)(pre-'a')] = 1;
		
		for(int i=1;i<str.length();i++)
		{
			 char cur = str.charAt(i);
			 if(alphabet[(int)(cur-'a')] == 1 && pre != cur)
				 return false;
			 alphabet[(int)(cur-'a')] = 1;
			 pre = cur;
		}
		
		return true;
	}
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), cnt = 0;
		
		for(int i=0;i<n;i++)
		{
			String str = in.next();
			if(solve(str))
				cnt++;
		}
		
		System.out.println(cnt);
	}
}