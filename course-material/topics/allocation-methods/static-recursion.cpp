// Should compute sum 1...n
int sum(int n)
{
  if ( n == 0 ) return 0;
  else return n + sum(n - 1);
}

sum(5); // returns `\only<handout:0|1>{?}\only<handout:1|2>{0}`
