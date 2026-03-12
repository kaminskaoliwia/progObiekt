package Segm;

public class Segm {

    private final static double PI = 3.14159265358979; // constant

    private Point mPt1;
    private Point mPt2; // to sa referencje i nie mamy jeszcze tych punktow
    //------------konstruktor-----

    public Segm() {
        this(0,0,0,0);
    }

    public Segm(Point mPt1, Point mPt2) {
        this(mPt1.getX(), mPt1.getY(), mPt2.getX(), mPt2.getY());
    }

    public Segm( double x1, double y1, double x2, double y2) {
        mPt1 = new Point(x1, y1);
        mPt2 = new Point(x2, y2);
    }

    public Segm(Segm segm) {
        this(segm.getPt1(), segm.getPt2());
    }

    public Point getPt1() {
        return mPt1;
    }

    public final void setPt1(Point pt1) {
        this.mPt1 = pt1;
        // mP1.setPoint(pt1)
    }

    public Point getPt2() {
        return mPt2;
    }

    public final void setPt2(Point pt2) {
        this.mPt2 = pt2;
    }

    //---------------------------

    public void setSegm(double x1, double y1, double x2, double y2) {
        mPt1.setPoint(x1, y1);
        mPt2.setPoint(x2, y2);
    }

    public void setSegm( Point pt1, Point pt2 ) {
        setPt1(pt1); setPt2(pt2);
    }

    public void setSegm(Segm segm) {
        setPt1(segm.getPt1()); setPt2(segm.getPt2());
    }

    //--------------------

    public void Translate( double vx, double vy ) {
        mPt1.Translate(vx, vy);
        mPt2.Translate(vx,vy);
    }

    public void Rotate(int alpha) {
        Point sr = new Point(ave(mPt1.getX(), mPt2.getX()), ave(mPt1.getY(), mPt2.getY()));
        double radians = deg2rad(alpha);

        Translate( -sr.getX(), -sr.getY() );
        mPt1.Rotate(radians);
        mPt2.Rotate(radians);
        Translate(sr.getX(), sr.getY());
    }

    public double Length() {
        return Math.sqrt( sqr(mPt1.getX()-mPt2.getX()) + sqr(mPt1.getY()- mPt2.getY()));
    }

    public String toString() {
        return mPt1.toString() + " --- " + mPt2.toString();
    }

    //---------------

    private double sqr( double a ) {
        return a*a;
    }

    private double ave(double a, double b) {
        return (a+b)/2;
    }

    private  double deg2rad(double alpha) {
        return PI*alpha/180;
    }
}
