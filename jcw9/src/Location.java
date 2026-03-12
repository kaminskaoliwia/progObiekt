
interface IStreet
{
    String mStreet = "Krakowska";
    int mHouse = 2;
    int mFlat = 34;
    default String getName() { return getInterface() + "IStreet"; }
    private String getInterface() { return "Interface ";}
}

interface ICity
{
    String mCity = "31-215 Krakow";
    String addr(); // metoda abstrakcyjna

}

public class Location implements IStreet, ICity
{
    Location() { }
    public String toString()
    {
        return addr() + mCity + ", street " + mStreet + String.format("%2d", mHouse) +
                String.format("%1d", mFlat);
    }

    @Override
    public String addr() {
        return "Address: ";
    }
}
