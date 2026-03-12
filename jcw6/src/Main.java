
class SuperClass {
    public SuperClass() {
        System.out.println("SUPER CLASS constructor");
    }
    // non-static block
    {
        System.out.println("superclass INSTANCE INIT block"); // to przed konstruktorem
    }
}

class Test extends SuperClass
{
    public Test()
    {
        super();
        System.out.println("Test -> constructor");
    }
    // static block
    static
    {
        System.out.println("** Test => STATIC INIT block **");
        // tylko raz przy tworzeniu pierwszego obiektu przed konstruktorem
    }
    // non-static blocks
    { // bloki niestatyczne po statycznym i w kolejnosci implementacji
        System.out.println("Test => INSTANCE INIT block #1");
    }

    {
        System.out.println("Test => INSTANCE INIT block #2");
    }
}

//-----------------------------------------------------------------------------------------

public class Main {
    public static void main( String[] args )
    {
        System.out.println("STATIC BLOCK TEST\n");
        System.out.println("Declare reference to Test obj: Test ts1");
        Test ts1; // to nie jest obiekt ale referencja do niego
        System.out.println("\nNew ts1 object");
        Test ts2 = new Test();
        System.out.println("\nNew ts3 object");
        Test ts3 = new Test();
    }
}

/* statyczny kod inicjujący = inicjowanie składowych klasy
w chwili tworzenia pierwszego obiektu klasy
static lub niestatic = wykonuje sie przed konstruktorem */