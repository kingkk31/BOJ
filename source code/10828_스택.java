import java.util.Scanner;
import java.util.Arrays;
import java.util.List;
import java.util.Comparator;
import java.math.BigInteger;

class Stack{
	int[] stack;
	int cnt;
	
	public Stack(int n)
	{
		stack = new int[n];
		cnt = -1;
	}
	
	public void push(int num)
	{
		stack[++cnt] = num;
	}
	
	public void pop()
	{
		if(cnt == -1)
			System.out.println(-1);
		else
			System.out.println(stack[cnt--]);
	}
	
	public void size()
	{
		System.out.println(cnt+1);
	}
	
	public void empty()
	{
		if(cnt == -1)
			System.out.println(1);
		else
			System.out.println(0);
	}
	
	public void top()
	{
		if(cnt == -1)
			System.out.println(-1);
		else
			System.out.println(stack[cnt]);
	}
}

public class Main {// BOJ

	int[] stack;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner in = new Scanner(System.in);
		
		int n;
		n = in.nextInt();
		
		Stack stack = new Stack(n);
		
		for(int i=0;i<n;i++)
		{
			String str = in.next();
			if(str.compareTo("push") == 0)
			{
				int num = in.nextInt();
				stack.push(num);
			}
			else
			{
				switch(str)
				{
				case "pop" : stack.pop(); break;
				case "size" : stack.size(); break;
				case "empty" : stack.empty(); break;
				case "top" : stack.top(); break;
				}
			}
		}
		
		
	}
}