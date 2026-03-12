public class X < T,K > {
    private T key;
    private K tab[]; // referencja do tablicy

    public X(T x, K t[], K k) {
        key = x;
        tab = t;
        for (int i = 0; i < t.length; i++) {
            tab[i] = k; }

        //for( K obj : t) { <-- nie dziala bo obj to referencja
        //  obj = k; }
    }

    public T getKey() {
        return key;
    }

    public K getTab()
    {
        return tab[0];
    }

}
