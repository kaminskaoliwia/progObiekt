import java.util.Scanner;
import java.util.*;

public class Main {
    public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    in.useLocale( Locale.US );

    System.out.print("Podaj liczbe double: ");
    double x = in.nextDouble();
    System.out.println("x = " + x);

    System.out.print("Podaj inta ");
    int y = in.nextInt();
    System.out.println("y = " + y);

    in.nextLine(); // wywolac jesli po czytaniu liczby mamy wczytac linie tekstu
    System.out.print("Podaj linie tekstu: ");
    String line = in.nextLine();
    System.out.println(" line = " + line);

    System.out.print("Podaj bajt: ");
    byte bt = in.nextByte();
    System.out.println("byte = " + bt);

    System.out.print("Podaj wartosc logiczna: ");
    boolean b = in.nextBoolean();
    System.out.println("Wartosc logiczna = " + b);

    System.out.print("Podaj jeden znak: ");
    char c;
    try {
        c = (char)System.in.read(); // read czyta liczby, wiec rzutujemy na char
    }
    catch( IDException e ) {
        c = 0x0a;
    }
    System.out.println("Wczytano znak: " + c + "kod znaku = " + (int)c);

    }
}