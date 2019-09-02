import java.io.*;
import java.util.*;
import java.math.*;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Solver solver = new Solver();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class Solver {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int a = in.nextInt();
            int b = in.nextInt();
            String num = in.next();

            BigInteger value = BigInteger.ZERO;
            for (int i = 0; i < num.length(); ++i) {
                value = value.multiply(BigInteger.valueOf(a));
                value = BigInteger.valueOf(getValue(num.charAt(i))).add(value);
            }
            out.println(a + " " + num);

            if (value.equals(BigInteger.ZERO)) {
                out.println(b + " 0");
                out.println();
                return;
            }

            out.print(b + " ");

            char[] ans = new char[1000];
            int length = 0;
            while (!value.equals(BigInteger.ZERO)) {
                int digit = value.mod(BigInteger.valueOf(b)).intValue();
                value = value.divide(BigInteger.valueOf(b));
                ans[length] = getChar(digit);
                ++length;
            }

            for (int i = length - 1; i >= 0; --i) {
                out.print(ans[i]);
            }
            out.println("\n");
        }

        private int getValue(char ch) {
            if (ch >= 'A' && ch <= 'Z') {
                return ch - 'A' + 10;
            }
            if (ch >= 'a' && ch <= 'z') {
                return ch - 'a' + 36;
            }
            return ch - '0';
        }

        private char getChar(int x) {
            if (x < 10) {
                return (char) ('0' + x);
            } else if (x < 36) {
                return (char) ('A' + x - 10);
            } else {
                return (char) ('a' + x - 36);
            }
        }

    }
}
