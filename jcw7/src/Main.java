
class  Main {
    public static void main(String[] args)
    {
        Integer t1[] = {-1, -2, -5};
        X<Integer, Integer> obj1 = new X<Integer, Integer>(5, t1, 20);
        System.out.println("key = " + obj1.getKey() + " tab[0] = " + obj1.getTab());

        String[] t2 = {"aaaa", "bbbb", "cccc", "dddd"};
        X<Integer, String> obj2 = new X<Integer, String>(20, t2, "1234");
        System.out.println("key = " + obj2.getKey() + " tab[0] = \"" + obj2.getTab() + "\"");
    }
}
/* dwie zmienne i jeden if do getChar()
ungetChar()
readInt wszystko metody statyczne, miedzy znakiem a liczba nie musi byc spacji
public static double getDouble()
szereg funkcji prywatnych */
