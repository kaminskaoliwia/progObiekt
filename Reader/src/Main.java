import Reader.Reader;

import java.io.IOException;

public class Main {
    public static void main( String[] args ) {

        System.out.println("Wpisz int: ");
        int i = Reader.readInt();
        System.out.println("INT: " + i);

        System.out.println("Wpisz double: ");
        double d = Reader.readDouble();
        System.out.println("DOUBLE: " + d);

        System.out.println("Wpisz hex: ");
        try { int h = Reader.readHex(); System.out.println("HEX jako dziesiętny: " + h); }
        catch (IOException e) {
            System.out.println("Błąd: " + e.getMessage());
        }
    }
}

