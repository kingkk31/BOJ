import java.util.*;
import java.math.*;

public class Main {// BOJ
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner in = new Scanner(System.in);
		String a = in.next();
		int b = in.nextInt();
		BigDecimal num = new BigDecimal(a);
		num = num.pow(b);
		System.out.print(num.toPlainString());
		in.close();
	}
}