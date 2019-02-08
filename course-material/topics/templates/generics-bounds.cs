interface IMuzzifiable {
  void Muzzify();
}

class Foo<T> `\pgfmark{type bound start}`where T : IMuzzifiable`\pgfmark{type bound end}`
{
  private T x;

  public void Frobnicate() {
    x.Muzzify();
  }
}