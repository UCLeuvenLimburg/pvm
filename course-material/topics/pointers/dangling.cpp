int* foo() {
  `\tikzmark{dangling x start}`int x = 2;`\tikzmark{dangling x end}`
  `\tikzmark{dangling p start}`int* p = &x;`\tikzmark{dangling p end}`
  return p;
}

void bar() {
  `\tikzmark{dangling q start}`int* q`\tikzmark{dangling q end}` = `\tikzmark{dangling call start}`foo();`\tikzmark{dangling call end}`
  std::cout << *q;
}

bar();
