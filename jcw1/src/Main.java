class X
{

}

public class Main
{
    private static int x = 123;
    public static void main(String[] args) // args = obiekt tablicowy, ilosc pol (length) jest zaszyta w tablicy, w przeciwenstwie do C
            // musza byc parametry
    {
        X x = null; // x to referencja do obiektu typu X
        x = new X(); // tworzenie dynamiczne
        String str = new String("2u3u3");
        String str2 = "djldjdkdjfd";
        double y = 324.48348;

        int len = args.length;

        System.out.println("x = " + getX() + ' ' + str + ' ' + str2 + " y= " + y);

        double yy = 1.24;
        double xx = 0xF0234AB1; // F najstarszy bajt = bit znaku = 1 = ujemna
        int xxx = 0b1011;
        yy = -Math.sqrt(16.) + xx++ / 0.2e-2;

        System.out.println("xx = " + xx + ' ' + "yy= " + yy);

    }

    private static int getX()
    {
        return x;
    }

}

/* Notatki
Program w Javie to zbiór klas
jedna klasa = jeden plik
dziedziczenie tylko pojedyncze - nie ma wielokrotnych
segregowanie klas w formie pakietów
gdy nie ma "public" przed class oznacza ze klasa jest publiczna tylko w danym pakiecie

kazda klasa domyslnie dziedziczy od klasy Objecy
kazda metode mozna przeciazyc (w przeciwienstwie do C gdzie tylko metody wirtualne)
mozna implementowac konstruktor, nie ma destruktorów

import static java.lang.Math.*
klasy importujemy tylko gdy sa w innych pakietach

Strumienie we/wy
System.out
System.in
System.err

System.out.println() <-- drukowanie z nowa linia na koncu

Typy podstawowe: --> obudowane w klasy, tworza obiekty
byte 1 ! nie ma w C --> Byte
char 2 ! w C ma 1 --> Character
int 4 --> Integer
short 2 --> Short
long 8
boolean ! zamiast bool
float 4 --> Float
double 8

liczb zmiennoprzecinkowych nie porownujemy przez == tylko przy abs()
wyrazenie pytajnikowe w nawiasach = poprawa czytelnosci

instanceof = sprawdza typ

public final static (np. int) STALA = 45

metody obiektu Scanner
 */