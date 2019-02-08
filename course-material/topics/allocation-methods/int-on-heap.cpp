int main()
{
  `\pgfmark{int pointer on stack start}`int* p`\pgfmark{int pointer on stack end}` = `\pgfmark{int on heap start}`new int`\pgfmark{int on heap end}`;

  *p = 5;
}
