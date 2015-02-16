import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for (int i = 0; i < n; ++i) {
			int pos = 0;
			int[] commands = new int[105];
			int c = in.nextInt();
			in.nextLine();
			for (int j = 1; j <= c; ++j) {
				String command = in.nextLine();
				switch (command) {
				case ("LEFT"):
					pos--;
					commands[j] = -1;
					break;
				case ("RIGHT"):
					pos++;
					commands[j] = 1;
					break;
				default:
					String[] split = command.split(" ");
					int com = Integer.parseInt(split[split.length - 1]);
					int val = commands[com];
					pos += val;
					commands[j] = val;
					break;
				}
			}
			System.out.println(pos);
		}
		in.close();
	}

}
