import java.util.Scanner;

public class Main {

	public static int fact(int n) {
		if (n <= 0) {
			return 1;
		}
		return fact(n - 1) * n;
	}

	public static int comb(int n, int k) {
		return fact(n) / (fact(k) * fact(n - k));
	}

	public static int solve(int n, int k, int num) {
		if (num == 1) {
			return k;
		}
		return solve(n, k, num - 1) + comb(k, num);
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			int N = in.nextInt();
			int K = in.nextInt();
			if (N == 0 && K == 0) {
				break;
			}
			System.out.println(solve(N, K, N));
		}
		in.close();
	}
}
