import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Olp_KC24_Prime {
    static ArrayList<Integer> prime = new ArrayList<>();
    static int[] lpf;

    static void sieve(int n) {
        prime.add(2);
        lpf = new int[n + 1];
        Arrays.fill(lpf, 2);

        for (int x = 3; x <= n; x += 2) {
            if (lpf[x] == 2) {
                lpf[x] = x;
                prime.add(x);
            }
            for (int i = 0; i < prime.size() && prime.get(i) <= lpf[x] && prime.get(i) * x <= n; i++) 
                lpf[prime.get(i) * x] = prime.get(i);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        StringBuilder out = new StringBuilder();

        sieve(1000006);
        st = new StringTokenizer(reader.readLine());
        BigInteger n = new BigInteger(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        BigInteger m = new BigInteger("0");
        for (int i = 0; i <= prime.size() - 3; i++) {
            BigInteger p1 = new BigInteger(prime.get(i).toString());
            BigInteger p2 = new BigInteger(prime.get(i + 1).toString());
            BigInteger p3 = new BigInteger(prime.get(i + 2).toString());
            for (int t2 = 1; p2.pow(t2).compareTo(n) <= 0; t2++) if (k % (t2 + 1) == 0) {
                for (int t3 = 1; p2.pow(t2).multiply(p3.pow(t3)).compareTo(n) <= 0; t3++) if ((k / (t2 + 1)) % (t3 + 1) == 0) {
                    int t1 = k / (t2 + 1) / (t3 + 1) - 1;
                    BigInteger x = p1.pow(t1).multiply(p2.pow(t2)).multiply(p3.pow(t3));
                    if (t1 >= 1 && x.compareTo(n) <= 0) m = m.max(x);
                }
            }
        }
        out.append(m.toString());

        writer.write(out.toString());
        writer.flush();
        reader.close();
        writer.close();
    }
}

// https://oj.vnoi.info/problem/olp_kc24_prime