package Segm;

class XX
{
    private int x;
    XX() { x = 1; }
}
public class Point {

    private double mX;
    private double mY;

    //----konstruktory-----

    public Point() {
        this(0,0); // wywolanie konstruktora z parametrami
    }

    public Point(double x, double y) {
        setX(x); setY(y);
    }

    public Point(Point pt) {
        this(pt.getX(), pt.getY());
    }

    public double getX() {
        return mX;
    }

    public void setX(double x) {
        this.mX = x;
    }

    public double getY() {
        return mY;
    }

    public void setY(double y) {
        this.mY = y;
    }

    //---------------------------------------

    public void setPoint(double x, double y)
    {
        setX(x); setY(y);
    }

    public void setPoint( Point pt )
    {
        setX(pt.getX()); setY(pt.getY());
    }

    public void Translate( double vx, double vy) {
        mX += vx;
        setY( getY() + vy );
    }

    public void Rotate( double radians ) {
        Point currPt = new Point(this); // wystarczyloby zapamietac tylko x

        mX = currPt.getX()*Math.cos( radians ) - currPt.getY()*Math.sin( radians );
        setY( currPt.getX()*Math.sin( radians ) + currPt.getY()*Math.cos( radians ));
    }

    public String toString() { //(1.234,0.345)
        return "(" + String.format("%.3f", getX()) + "," + String.format("%.3f", getY()) +  ")";
    }
}
