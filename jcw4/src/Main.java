
public class Main
{
    public static void main(String[] args)
    {
        Stack s = new Stack();
        s.push('A');
        s.push('B');
        s.push('C');

        try {
            System.out.println(s.pop() + s.pop() + s.pop()); // traktuje na intach
            s.del();
        }
        catch (StackException e)
        {
            System.out.println(e.getReason());
        }
        }
}