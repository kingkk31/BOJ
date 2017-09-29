import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner keyboard = new Scanner(System.in);
		
		String str1 = keyboard.next();
		String str2 = keyboard.next();
		
		BigInteger num1 = new BigInteger(str1);
		BigInteger num2 = new BigInteger(str2);
		
		System.out.println(num1.add(num2));
	}

}