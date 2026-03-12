// import Segm.Segm;
//import Segm.Point;
import Segm.*;

public class Main
{
    public static void main(String[] args) {

        Point pt = new Point(1,3);
        Segm seg = new Segm(1,0,0,1);
        System.out.println(seg.toString());
        System.out.println("Dlugosc odcinka = " + seg.Length());

        int alpha = 45;
        seg.Rotate(alpha);
        System.out.println("Po obrocie o kat " + alpha + "=" + seg.toString());
        System.out.println("Dlugosc odcinka = " + seg.Length());

    }
}