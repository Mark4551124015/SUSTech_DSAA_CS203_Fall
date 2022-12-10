import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Week12_D_Brute {
    public static final QReader in = new QReader();
    public static int C;
    public static void main(String[] args) {
        ArrayList<Integer> commands = new ArrayList<>();
        C = in.nextInt();
        int n = in.nextInt();
        for(int i = 0; i < n; i++){
            commands.add(in.nextInt());
        }
        int m = in.nextInt();
        for(int i = 0; i < m; i++){
            checkCommand(in.next(),commands);
        }
    }

    public static void checkCommand(String cmd, ArrayList<Integer> commands){
        if(cmd.equals("rem")){
            int n = in.nextInt();
            commands.remove(n - 1);
        }else if(cmd.equals("ins")){
            int n = in.nextInt() - 1;
            int key = in.nextInt();
            commands.add(n,key);
        }else if(cmd.equals("ask")){
            int n = in.nextInt();
            if(commands.size() == 0){
                System.out.println(n);
            }else {
                for (Integer i : commands) {
                    n = n + i;
                    if (n > C) {
                        n = C;
                    }
                    if (n < 0) {
                        n = 0;
                    }
                }
                System.out.println(n);
            }
        }
    }
}

class QReader {
    private BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private StringTokenizer tokenizer = new StringTokenizer("");

    private String innerNextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
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

    public String nextLine() {
        tokenizer = new StringTokenizer("");
        return innerNextLine();
    }

    public String next() {
        hasNext();
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}


