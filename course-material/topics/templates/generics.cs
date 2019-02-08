// C# code (Java is more complicated)
class List`\pgfmark{list type parameter start}`<T>`\pgfmark{list type parameter end}` {
  private `\pgfmark{list items field type start}`T[]`\pgfmark{list items field type end}` items;
  private int size;

  public List() { items = new `\pgfmark{list items field initialization start}`T[10]`\pgfmark{list items field initialization end}`; }

  public void Add(`\pgfmark{list add parameter type start}`T`\pgfmark{list add parameter type end}` x) {
    if ( size == items.Length )
       DoubleCapacity();

    items[size] = x;
    size++;
  }
}