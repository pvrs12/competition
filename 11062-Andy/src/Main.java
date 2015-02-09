import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {

	public static boolean isAlpha(char c) {
		return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
	}

	public static ArrayList<String> getWords(String line) {
		ArrayList<String> words = new ArrayList<>();
		int start = 0;
		for (int i = 0; i < line.length(); ++i) {
			char c = line.charAt(i);
			if (!(isAlpha(c) || c == '-')) {
				// new word
				words.add(line.substring(start, i));
				start = i + 1;
			}
		}
		return words;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		TreeSet<String> werdz = new TreeSet<String>();

		while(in.hasNext()){
			String line = in.nextLine();
			
			
		}
		
		in.close();
	}

}
