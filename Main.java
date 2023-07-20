import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        
        AcWing solver = new AcWing();
        solver.solve(in, out);

        out.close();
    }

    static class AcWing {
        public void solve(InputReader in, PrintWriter out) {
            BigInteger a = in.nextBigInteger();
            BigInteger b = in.nextBigInteger();
            out.println(a.add(b).toString());
        }
    }

    static class InputReader {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = new StringTokenizer("");
        }
        private String innerNextLine() {
            try {
                return reader.readLine();
            } catch (IOException ex) {
                return null;
            }
        }
        public boolean hasNext() {
            while (!tokenizer.hasMoreTokens()) {
                String nextLine = innerNextLine();
                if (nextLine == null) {
                    return false;
                }
                tokenizer = new StringTokenizer(nextLine);
            }
            return true;
        }
        public String next() {
            if (hasNext()) {
                return tokenizer.nextToken();
            }
            return null;
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public BigInteger nextBigInteger() {
            return new BigInteger(next());
        }
    }
}
