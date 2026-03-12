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
    private class StackItem {
        char pInfo;
        StackItem pNext;

        public StackItem(char info, StackItem next) {
            this.pInfo = info;
            this.pNext = next;
        }

        public char getInfo() {
            return pInfo;
        }

        public void setInfo(char info) {
            this.pInfo = info;
        }

        public StackItem getNext() {
            return pNext;
        }

        public void setNext(StackItem next) {
            this.pNext = next;
        }

    }

    private StackItem pHead = null;

    public void push(char info) {
        pHead = new StackItem(info, pHead);
    }

    public char top() {
        if (isEmpty()) throw new StackException(ErrCode.STACK_IS_EMPTY);
        return pHead.getInfo();
    }

    public void del() {
        if (isEmpty()) throw new StackException(ErrCode.STACK_IS_EMPTY);
        pHead = pHead.getNext();
    }

    public char pop() {
        char info = top();
        del();
        return info;
    }

    public boolean isEmpty() {
        return pHead == null;
    }
}
