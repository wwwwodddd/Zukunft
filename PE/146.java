import java.math.BigInteger;
import java.util.Scanner;

public class PE146 {

	public static void main(String[] args) {
		for (long i = 0; i < 150000000; i += 10) {
			if (i * i % 7 != 2) {
				continue;
			}
			if (i * i % 3 != 1) {
				continue;
			}
			BigInteger a = BigInteger.valueOf(i * i);
			a = a.nextProbablePrime();
			if (a.longValue() - i * i != 1) {
				continue;
			}
			a = a.nextProbablePrime();
			if (a.longValue() - i * i != 3) {
				continue;
			}
			a = a.nextProbablePrime();
			if (a.longValue() - i * i != 7) {
				continue;
			}
			a = a.nextProbablePrime();
			if (a.longValue() - i * i != 9) {
				continue;
			}
			a = a.nextProbablePrime();
			if (a.longValue() - i * i != 13) {
				continue;
			}
			a = a.nextProbablePrime();
			if (a.longValue() - i * i != 27) {
				continue;
			}
			System.out.println(i);
		}
	}
}
