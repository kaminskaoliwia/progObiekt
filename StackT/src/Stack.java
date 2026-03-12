
enum ErrCode { STACK_ALLOCATION(1), STACK_IS_EMPTY(2), OTHER_ERROR(0);
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
            case STACK_ALLOCATION:
                return "ERROR: Allocation error";
            case STACK_IS_EMPTY:
                return "ERROR: Stack is empty";
            default: return "Other error";
        }
    }
}

public class Stack<T> {

    private class StackItem<T>
    {
        private T mKey;
        private StackItem<T> mNext;
        public StackItem(T obj, StackItem next)
        { mKey = obj; mNext = next; }

        //-----gettery-i-settery-----
        public T getKey() {
            return mKey;
        }

        public final void setKey(T key) {
            this.mKey = key;
        }

        public StackItem<T> getNext() {
            return mNext;
        }

        public final void setNext(StackItem<T> next) {
            this.mNext = next;
        }
    }

    private StackItem<T> pHead = null;

    public Stack() {}

    public void push(T item) {
        try {
        pHead = new StackItem<T>(item,pHead); }
        catch ( OutOfMemoryError e ) {
            throw new StackException(ErrCode.STACK_ALLOCATION);
        }
    }

    public T top() {
        if (isEmpty()) {
            throw new StackException(ErrCode.STACK_IS_EMPTY);
        }
        return pHead.getKey();
    }

    public void del() {
        if (isEmpty()) {
            throw new StackException(ErrCode.STACK_IS_EMPTY);
        }
        pHead = pHead.getNext();
    }

    public T pop() {

        if (isEmpty()) {
            throw new StackException(ErrCode.STACK_IS_EMPTY);
        }

        T info = top();
        del();
        return info;
    }

    public boolean isEmpty() {
        return pHead == null;
    }
}
