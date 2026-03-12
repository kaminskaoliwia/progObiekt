
enum ErrCode { STACK_OVERFLOW(1), STACK_IS_EMPTY(2), OTHER_ERROR(0);
private int mCode;
ErrCode(int code) { mCode = code; }
}

class StackException extends RuntimeException //lub Exception
{
    private ErrCode mErrCode;
    StackException( ErrCode errCode) { mErrCode = errCode; }
    String getReason()
    {
        switch( mErrCode ) {
            case STACK_OVERFLOW:
                return "ERROR: Stack overflow";
            case STACK_IS_EMPTY:
                return "ERROR: Stack is empty";
            default: return "Other error";
        }
    }
}

public class Stack {
    private final static int MAXSTACK = 10;
    private char StackTab[];
    private int mHead;

    public Stack()
    {
        mHead = 0; StackTab = new char[MAXSTACK];
    }
    public void push( char c )
    {
        if( mHead >= MAXSTACK )
            //System.err.println("Stack overflow !!");
            throw new StackException( ErrCode.STACK_OVERFLOW);
            //else
        StackTab[mHead++] = c;
    }

    public char pop()
    {
        if(!isEmpty()) {
            char c = top();
            del();
            return c;
        }
        //System.err.println("Stack is empty !!");
        throw new StackException(ErrCode.STACK_IS_EMPTY);
        //return 0;
    }

    public char top()
    {
        if( !isEmpty() )
        {
            return StackTab[mHead-1];
        }
        //System.err.println("Stack is empty !!");
        throw new StackException(ErrCode.STACK_IS_EMPTY);
        //return 0;
    }

    public void del()
    {
        if(!isEmpty())
        {
            mHead--;
        }
        else {
            //System.err.println("Stack is empty !!");
            throw new StackException(ErrCode.STACK_IS_EMPTY);
        }
    }

    public boolean isEmpty()
    {
        return mHead == 0; // nie wolno !mHead niestety
    }
}

