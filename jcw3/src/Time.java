import java.time.LocalDate;

public class Time {

    private final static int defDay = 1;
    private final static int defMonth = 1;
    private final static int defYear = 1990;

    public Time()
    {
        this(defDay, defMonth, defYear, 0, 0, 0); // wywolanie konstruktora z parametrami
    }

    public  Time(int D, int M, int Y, int h, int m, int s)
    {

    }

    public Time(Time t )
    {
        setTime(t.getDay(), t.getMonth(), t.getYear(), t.getHour(), t.getMin(), t.getSec());
    }

    public void setTime(int D, int M, int Y, int h, int m, int s)
    {
        setDate(D, M, Y);
        setClockTime(h,m,s);
    }

    public void setDate(int D, int M, int Y)
    {
     setDay(D); setMonth(M); setYear(Y);
    }

    public void setClockTime(int h, int m, int s)
    {
        setHour(h); setMin(m); setSec(s);
    }

    //-------gettery-------------------------------------------------------------
    public int getDay() { return mDay; }

    public int getMonth() { return mMonth; }

    public int getYear() { return mYear; }

    public int getHour() { return mHour; }

    public int getMin() { return mMin; }

    public int getSec() { return mSec; }

    //-------settery-------------------------------------------------------------
    public void setDay(int Day) { this.mDay = Day; }

    public void setMonth(int Month) { this.mMonth = Month; }

    public void setYear(int Year) { this.mYear = Year; }

    public void setHour(int Hour) { this.mHour = Hour; }

    public void setMin(int Min) { this.mMin = Min; }

    public void setSec(int Sec) { this.mSec = Sec; }

    //------------------------------------------------------------------------

    public String toString()
    {
        return toDateString() + "--" + toTimeString();
    }

    public String toDateString()
    {
        return Integer.toString(getDay()) + "/" + Integer.toString(getMonth()) + "/" + Integer.toString(getYear());
    }

    public String toTimeString()
    {
        return Integer.toString(getHour()) + ":" + Integer.toString(getMin()) + ":" + Integer.toString(getSec());

    }
    public String nameOfMonth( int M )
    {
        switch( M ) {
            case 1:
                return "JAN";
            case 2:
                return "FEB";
            case 3:
                return "MAR";
            case 4:
                return "APR";
            case 5:
                return "MAY";
            case 6:
                return "JUN";
            case 7:
                return "JUL";
            case 8:
                return "AUG";
            case 9:
                return "SEP";
            case 10:
                return "OCT";
            case 11:
                return "NOV";
            case 12:
                return "DEC";
        }
        return "";
    }

    public String nameOfDay( int D )
    {
        LocalDate sdf = LocateDate.of(getYear(), getMonth(), getDay());
        // return sdf.getDayofWeek().toString();
        String s = sdf.getDayofWeek().toString.substring(3);
        return String.format("%.3s", s);
    }

    public String toDateTimeNameString()
    {
        return Integer.toString(getDay()) + "(" + nameOfDay(getDay()) + ")"
                + nameOfMonth(getMonth()) + " " + Integer.toString(getYear());
    }

    private int mDay;
    private int mMonth;
    private int mYear;

    private int mHour;
    private int mMin;
    private int mSec;
}
