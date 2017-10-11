import java.util.*;
import java.math.*;

public class Main {// BOJ
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), ans = 0;
		int[][] map = new int[101][101];
		
		for(int i=0;i<n;i++)
		{
			int x = in.nextInt(), y = in.nextInt();
			
			for(int a=1;a<=10;a++)
				for(int b=1;b<=10;b++)
					map[x+a][y+b] = 1;				
		}
		
		for(int i=0;i<=100;i++)
			for(int j=0;j<=100;j++)
				if(map[i][j] == 1)
					ans++;
		System.out.println(ans);
	}
}