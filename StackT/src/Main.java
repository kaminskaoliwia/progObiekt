public class Main {
    public static void main( String[] args )
    {
        Stack<Character> cStack = new Stack<Character>();
        Stack<Integer> iStack = new Stack<Integer>();


        try{
            cStack.push('A');
            cStack.push('B');
            cStack.push('C');

            iStack.push(1);
            iStack.push(2);
            iStack.push(3);

            System.out.println( ""+ cStack.pop() + cStack.pop() + cStack.pop()  );
            System.out.println( ""+ iStack.pop() + iStack.pop() + iStack.pop()  );
            System.out.println( ""+ cStack.pop() );

        }
        catch( StackException e )
        {
            System.out.println( e.getReason() );
        }
    }
}