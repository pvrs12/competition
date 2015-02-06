import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static boolean isAlpha(char c) {
		return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		ArrayList<String> werdz = new ArrayList<String>();
		while (in.hasNext()) {
			String str = in.nextLine();
			if (str.length() == 0) {
				continue;
			}
			String[] strs = str.split(" ");
			for (int i = 0; i < strs.length - 1; ++i) {
				werdz.add(strs[i].toLowerCase());
			}

			StringBuilder sb = new StringBuilder(strs[strs.length - 1]);
			if (sb.length() == 0) {
				// read blank line don't worry about it
				continue;
			}
			if (sb.charAt(sb.length() - 1) == '-') {
				// last char in line is -
				while (true) {

					String str2 = in.nextLine();
					if (str2.length() == 0) {
						continue;
					}
					String[] nexts = str2.split(" ");
					if (nexts.length == 1) {
						// then only 1 word
						if (!(nexts[0].charAt(nexts[0].length() - 1) == '-')) {
							// done word
							// append then break
							sb = new StringBuilder(sb.substring(0,
									sb.length() - 1));
							sb.append(nexts[0]);
							werdz.add(sb.toString().toLowerCase());
							break;
						} else {
							// no more words on line last char is '-'
							// append this word and read next line
							sb = new StringBuilder(sb.substring(0,
									sb.length() - 1));
							sb.append(nexts[0]);
						}
					} else {
						// multiple words in the line
						// the first word must be the end of the hyphenated word
						sb = new StringBuilder(sb.substring(0, sb.length() - 1));
						sb.append(nexts[0]);
						werdz.add(sb.toString().toLowerCase());

						for (int i = 1; i < nexts.length - 1; ++i) {
							werdz.add(nexts[i].toLowerCase());
						}
						// must check last word for hyphen at the end
						if (nexts[nexts.length - 1]
								.charAt(nexts[nexts.length - 1].length() - 1) == '-') {
							sb = new StringBuilder(nexts[nexts.length - 1]);
							// do the loop again with a new string builder
						} else {
							werdz.add(nexts[nexts.length - 1].toLowerCase());
							break;
						}
					}

				}
			} else {
				werdz.add(sb.toString().toLowerCase());
			}
		}

		// remove punctuation
		for (int i = 0; i < werdz.size(); ++i) {
			String s = werdz.get(i);
			for (int j = 0; j < s.length(); ++j) {
				char a = s.charAt(j);
				if (!(isAlpha(a) || a == '-')) {
					// remove dat ish
					if (j == 0) {
						s = s.substring(j + 1);
					} else if (j == s.length() - 1) {
						s = s.substring(0, j);
					} else {
						s = s.substring(0, j) + s.substring(j + 1);
					}
				}
			}
			werdz.set(i, s);
		}
		ArrayList<String> werdz2 = new ArrayList<String>();

		// remove dupies
		for (String s : werdz) {
			if (s == "") {
				continue;
			}
			if (werdz2.contains(s)) {
				continue;
			} else {
				werdz2.add(s);
			}
		}
		werdz = werdz2;

		Collections.sort(werdz);

		for (String s : werdz) {
			System.out.println(s);
		}
		in.close();
	}

}
