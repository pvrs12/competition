import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static BigInteger fact(BigInteger n) {
		if (n.longValue() <= 0) {
			return BigInteger.ONE;
		}
		return n.multiply(fact(n.subtract(BigInteger.ONE)));
	}

	public static BigInteger comb(int n, int k) {
		BigInteger bi = fact(new BigInteger("" + n)).divide(
				fact(new BigInteger(k + "")).multiply(
						new BigInteger((n - k) + "")));

		return bi;
	}

	// public static int solve(int n, int k, int num) {
	// if (num == 1) {
	// return k;
	// }
	// return solve(n, k, num - 1) + comb(k, num);
	// }

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			int N = in.nextInt();
			int K = in.nextInt();
			if (N == 0 && K == 0) {
				break;
			}
			BigInteger res = BigInteger.ZERO;
			for (int i = 2; i <= K; ++i) {
				res = res.add(comb(K + N - 1, N));
			}
			//res = res.mod(new BigInteger("1000000"));
			System.out.println(res);
		}
		in.close();
	}
}
