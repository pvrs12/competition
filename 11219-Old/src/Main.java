import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws ParseException {
		Scanner s = new Scanner(System.in);

		int cases = s.nextInt();
		for (int i = 0; i < cases; ++i) {
			String todays = s.next();
			String bdays = s.next();
			SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy");
			Calendar bday = Calendar.getInstance();
			Calendar today = Calendar.getInstance();
			bday.setTime(format.parse(bdays));
			today.setTime(format.parse(todays));
			System.out.print("Case #" + (i + 1) + ": ");
			if (today.before(bday)) {
				System.out.println("Invalid birth date");
			} else {
				int curYear = today.get(Calendar.YEAR);
				int curMonth = today.get(Calendar.MONTH);
				int curDay = today.get(Calendar.DAY_OF_MONTH);

				int bYear = bday.get(Calendar.YEAR);
				int bMonth = bday.get(Calendar.MONTH);
				int bDay = bday.get(Calendar.DAY_OF_MONTH);

				int age = curYear - bYear;
				if (curMonth < bMonth || (bMonth == curMonth && curDay < bDay)) {
					age--;
				}

				if (age > 130) {
					System.out.println("Check birth date");
				} else {
					System.out.println(age >= 0 ? age : 0);
				}
			}
		}
		s.close();
	}
}
