import java.util.*;
import java.math.*;

public class Main {// BOJ
	
	public static void solve(int r, int c, String []field)
	{
		int []arr = {0, 0, 0, 0, 0};
		int []dy = {0, 0, 1, 1};
		int []dx = {0, 1, 0, 1};
		
		for(int i=0;i<r-1;i++)
		{
			loop :
			for(int j=0;j<c-1;j++)
			{
				int cnt = 0;
				for(int k=0;k<4;k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					
					if(field[ny].charAt(nx) == '#')
						continue loop;
					
					if(field[ny].charAt(nx) == 'X')
						cnt++;
				}
				arr[cnt]++;
			}
		}
		
		for(int i=0;i<5;i++)
			System.out.println(arr[i]);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner in = new Scanner(System.in);

		int r,c;
		r = in.nextInt();
		c = in.nextInt();
		
		String []field = new String[r];
		for(int i=0;i<r;i++)
			field[i] = in.next();
		
		solve(r, c, field);
		in.close();
		
	}
}