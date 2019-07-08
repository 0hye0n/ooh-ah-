import java.util.*;
import java.math.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		BigInteger sum = new BigInteger("0");
		for(int i = 0; i<n; i++)
		{
			BigInteger result = new BigInteger("0");
			BigInteger temp = new BigInteger("1");
			int a, b;
			a = s.nextInt();
			b = s.nextInt();
			while(b>0)
			{
				result = result.add(temp.multiply(BigInteger.valueOf(b).remainder(BigInteger.valueOf(2))));
				b /= 2;
				temp = temp.multiply(BigInteger.valueOf(a));
			}
			sum = sum.add(result);
		}	
		System.out.println(sum.remainder(BigInteger.valueOf(1000000007)));
	}
}