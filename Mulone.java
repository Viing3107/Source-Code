import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Mulone {
    private static String solve(int n) {
        int m = 2 * n - 1;
        int[] digits = new int[m];

        for (int k = 0; k < m; k++) {
            digits[k] = Math.min(k + 1, m - k);
        }

        int carry = 0;
        for (int k = m - 1; k >= 0; k--) {
            int v = digits[k] + carry;
            digits[k] = v % 10;
            carry = v / 10;
        }

        StringBuilder sb = new StringBuilder(m);
        if (carry > 0) sb.append(carry);
        for (int d : digits) sb.append(d);
        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int q = Integer.parseInt(reader.readLine());
        StringBuilder out = new StringBuilder();

        for (int i = 0; i < q; i++) {
            int n = Integer.parseInt(reader.readLine());
            out.append(solve(n)).append("\n");
        }

        writer.write(out.toString());
        writer.flush();
        writer.close();
        reader.close();
    }
}

// https://oj.vnoi.info/problem/mulone