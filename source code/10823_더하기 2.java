import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Comparator;
import java.math.BigInteger;

class AddString{
	String str;
	int sum;
	
	public AddString()
	{
		str = "";
		sum = 0;
	}
	
	public void makeString(String str)
	{
		this.str += str;
	}
	
	public void makeNums()
	{
		this.str = (new StringBuffer(this.str)).reverse().toString();
		int cnt = 0, temp = 0;
		
		for(int i=0;i<str.length();i++)
		{
			char c = str.charAt(i); 
			if(c == ',')
			{
				sum += temp;
				temp = 0;
				cnt = 0;
			}
			else
			{
				temp += ((int)(c-'0')) * Math.pow(10, (double)cnt);
				cnt++;
			}
		}
		sum += temp;
	}
	
	public void print()
	{
		System.out.println(sum);
	}
}

public class Main {// BOJ

	int[] stack;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner in = new Scanner(System.in);
		
		AddString add = new AddString();
		String str;
		
		while(in.hasNext())
		{
			str = in.next();
			add.makeString(str);
		}
		
		add.makeNums();
		add.print();
		
	}
}