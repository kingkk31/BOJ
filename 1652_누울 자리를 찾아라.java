import java.util.*;
import java.math.*;

public class Main {// BOJ
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		String[] room = new String[n];
		in.nextLine();
		
		
		for(int i=0;i<n;i++)
			room[i] = in.nextLine();
		
		int cnt = 0;
		
		for(int i=0;i<n;i++)
		{
			int len = 0;
			
			for(int j=0;j<n;j++)
			{
				if(room[i].charAt(j)== '.')
					len++;
				else
				{
					if(len >= 2)
						cnt++;
					len = 0;
				}
			}
			
			if(len >= 2)
				cnt++;
			len = 0;
		}
		
		System.out.print(cnt + " ");
		cnt = 0;
		
		for(int i=0;i<n;i++)
		{
			int len = 0;
			
			for(int j=0;j<n;j++)
			{
				if(room[j].charAt(i)== '.')
					len++;
				else
				{
					if(len >= 2)
						cnt++;
					len = 0;
				}
			}
		
			if(len >= 2)
				cnt++;
			len = 0;
		
		}
		
		System.out.println(cnt);
		
		in.close();
	}
}