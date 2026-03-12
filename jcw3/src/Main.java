
public class Main
{
  public static void main(String[] args)
  {
    Time t = new Time();
    Time t1 = new Time(15,12, 2025, 17,1, 20);

    System.out.println("t =" + t.toString());
    System.out.println("t1 = " + t1.toDateTimeNameString());
  }
}