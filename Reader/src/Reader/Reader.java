package Reader;
import java.io.IOException;

public class Reader {
    private static int unget = -10;
    // -10 oznacza ze nic nie jest zapamietane, bo nie ma znaku z takim kodem

    public static char getChar() {
        try {
            int kod;
            if ( unget != -10 ) {
                kod = unget;
                unget = -10;
            }
            else {
                kod = System.in.read();
            }

            if (kod == -1) return '\0'; // -1 to znak konca
            return (char)kod;

        } catch (IOException e) {
            return '\0';
        }
    }

    public static void ungetChar( char c ) {
        unget = (int)c; // kod
    }

    public static int readInt() {
        skipSpaces();
        boolean positive = getSign();
        int val = readNum();
        return positive ? val : -val;
    }

    public static double readDouble() {
        skipSpaces();
        boolean positive = getSign();
        double val = (double)readNum(); // przestanie gdy znak nie jest liczbą

        char c = getChar();
        if ( c == '.' || c == ',') {
                double factor = 0.1;
                while (isDecDigit(c = getChar())) {
                    val += (c - '0') * factor;
                    factor *= 0.1;
                }
        }
        ungetChar(c);
        return positive ? val : -val;
    }

    public static int readHex() throws IOException {
        skipSpaces();
        int res = 0;
        char c;

        char c1 = getChar();
        if (c1 != '0')
            throw new IOException("Wrong hexadecimal prefix! Should be 0x or 0X");

        char c2 = getChar();
        if (upperCase(c2) != 'X')
            throw new IOException("Wrong hexadecimal prefix! Should be 0x or 0X" + c2);

        while (isHexDigit(c = upperCase(getChar()))) {
            res = res * 16 + charHexDigit2Int(c);
        }
        ungetChar(c);
        return res;
    }

// zapamietuje zmienna i zapamietuje

    //========= PRIVATE INTERFACE ================================
    private static int readNum() {
        char c;
        int res = 0;

        while(isDecDigit(c=getChar()))
            res = res * 10 + (c - '0');

        ungetChar(c);
        return res;
    }

    private static boolean getSign() {
        skipSpaces();
        char c = getChar();
        if( c == '-' ) return false;
        if (c != '+' ) ungetChar(c);
        return true;
    }

    private static void skipSpaces()
    {
        char c;
        while (true) {
            c = getChar();
            if (c != ' ' && c != '\n' && c != '\t' && c != '\r') {
                break;
            }
        }
        ungetChar(c);
    }

    private static boolean isDecDigit( char c ) {
        return c >= '0' && c <= '9';
    }

    private static int charHexDigit2Int( char c ) {
        return (isDecDigit(c)) ? (c - '0') : (upperCase(c) -'A' + 10 ); // A = 10
    }

    private static boolean isHexDigit( char c ) {
        return (isDecDigit(c) || isHexLetter(c)) ;
    }

    private static boolean isHexLetter( char c ) {

        return c >= 'A' && c <= 'F' || (c >= 'a' && c <= 'f');
    }

    private static char upperCase( char c ) {
        return (c>='a' && c <='z') ? (char)(c-32) : c ; // 32 = roznica miedzy wielkimi i malymi literami
    }
}