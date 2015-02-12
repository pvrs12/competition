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
				String s = line.substring(start, i).toLowerCase();
				if (!s.equals("")) {
					words.add(s);
				}
				start = i + 1;
			}
		}
		String s = line.substring(start).toLowerCase();
		if (!s.equals("")) {
			words.add(s);
		}
		return words;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		TreeSet<String> werdz = new TreeSet<String>();

		StringBuilder hyphen = null;
		while (in.hasNext()) {
			String line = in.nextLine();
			ArrayList<String> words = getWords(line);

			if (words.size() < 1) {
				continue;
			}

			// word at the beginning
			if (hyphen == null) {
				// if no hyphen previously
				String s = words.get(0);
				if (s.charAt(s.length() - 1) == '-' && words.size() == 1) {
					hyphen = new StringBuilder(s);
					// System.err.println("new-hyphen=" + hyphen);
				} else {
					werdz.add(s);
				}
			} else {
				// append to previous word
				hyphen = new StringBuilder(hyphen.substring(0,
						hyphen.length() - 1)).append(words.get(0));

				// System.err.println("hyphen-append=" + hyphen);
			}

			// if there was online one word, then we're done
			if (words.size() == 1) {
				// check if the last char is not a hyphen, if not, then put it
				// on the tree set
				if (hyphen != null && hyphen.charAt(hyphen.length() - 1) != '-') {
					werdz.add(hyphen.toString());
					// System.err.println("done-hyphen:" + hyphen);
					hyphen = null;
				}
				continue;
			}
			// words in the middle
			for (int i = 1; i < words.size() - 1; ++i) {
				// if there was a hyphenated word, and we are in here
				// then that word must be finished even if it ends with hyphens
				// because there are more in the line
				if (hyphen != null) {
					// System.err.println("done-hyphen:" + hyphen);
					werdz.add(hyphen.toString());
				}
				hyphen = null;
				// normally jsut add words
				werdz.add(words.get(i));
			}

			String s = words.get(words.size() - 1);
			if (s.equals("")) {
				continue;
			}
			// if the last word ends in a hyphen then smack it in hyphen
			if (s.charAt(s.length() - 1) == '-') {
				hyphen = new StringBuilder(s);
				// System.err.println("new-hyphen=" + hyphen);
			} else {
				// otherwise smack it onto the set
				werdz.add(s);
				hyphen = null;
			}

		}

		for (String s : werdz) {
			if (!s.equals(""))
				System.out.println(s);
		}

		in.close();
	}

}
