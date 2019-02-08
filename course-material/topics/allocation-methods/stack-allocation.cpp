int sum(`\pgfmark{stack sum param start}`int`\pgfmark{stack sum param end}` n)
{
  if ( n == 0 )
    return 0;
  else
  {
    int `\pgfmark{stack sum local start}`r`\pgfmark{stack sum local end}` = `\pgfmark{stack sum recursion start}`sum(n - 1)`\pgfmark{stack sum recursion end}`;
    return n + r;
  }
}

// Globals
int `\pgfmark{stack sum global n start}`n`\pgfmark{stack sum global n end}` = `\pgfmark{stack input start}`AskUserForInt()`\pgfmark{stack input end}`;
int `\pgfmark{stack sum global r start}`r`\pgfmark{stack sum global r end}` = sum(n);
std::cout << r << std::endl;
