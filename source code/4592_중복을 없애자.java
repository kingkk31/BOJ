import java.util.*;
import java.io.*;
import java.math.*;

public class Main {// BOJ
	
	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String input;
		StringTokenizer tok;
		ArrayList<String> submit;
		
		while(true)
		{
			input = in.nextLine();
			tok = new StringTokenizer(input);
			
			int cnt = Integer.parseInt(tok.nextToken());
			if(cnt == 0)
				break;
			
			submit = new ArrayList();
			while(tok.hasMoreTokens())
			{	
				String temp = tok.nextToken();
				if(submit.isEmpty() || !submit.get(submit.size() - 1).equals(temp))
					submit.add(temp);
			}
			
			for(String i : submit)
				System.out.print(i + " ");
			System.out.println("$");
		}
	}
}