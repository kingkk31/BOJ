import java.util.*;
import java.math.*;

public class Main {// BOJ
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner in = new Scanner(System.in);
		String str = in.next();
		
		int cnt = 0, i=0;
		while(i < str.length())
		{
			switch(str.charAt(i))
			{
			case 'c' :
				if(i + 1 < str.length() && (str.charAt(i + 1) == '=' || str.charAt(i + 1) == '-'))
					i += 2;
				else
					i++;
				break;
			case 'd' :
				if(i + 1 < str.length() && str.charAt(i + 1) == '-')
					i += 2;
				else if(i + 1 < str.length() && str.charAt(i + 1) == 'z' && i + 2 < str.length() && str.charAt(i + 2) == '=')
					i += 3;
				else
					i++;
				break;
			case 'l' :
				if(i + 1 < str.length() && str.charAt(i + 1) == 'j')
					i += 2;
				else
					i++;
				break;
			case 'n' :
				if(i + 1 < str.length() && str.charAt(i + 1) == 'j')
					i += 2;
				else
					i++;
				break;
			case 's' :
				if(i + 1 < str.length() && str.charAt(i + 1) == '=')
					i += 2;
				else
					i++;
				break;
			case 'z' :
				if(i + 1 < str.length() && str.charAt(i + 1) == '=')
					i += 2;
				else
					i++;
				break;
			default : 
				i++;
				break;
			}
			
			cnt++;	
		}
		
		System.out.println(cnt);
	}
}