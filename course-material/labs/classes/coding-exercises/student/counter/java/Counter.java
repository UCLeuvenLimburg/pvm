public class Counter
{
    private int value; // can never go below zero

    public Counter()
    {
        this(0);
    }
    
    public Counter(int initialValue)
    {
        this.value = initialValue;
    }

    public int getValue()
    {
        return value;
    }

    public void setValue(int value)
    {
        this.value = value;
    }

    public void increment()
    {
        ++value;
    }

    public void reset()
    {
        value = 0;
    }
}
