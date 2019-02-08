// Not real C++ syntax
void div(int x,
         int y,
         address_of_int q,
         address_of_int r) {
  write_int_to_address(q, ...);
  write_int_to_address(r, ...);
}

void func() {
  int q, r;
  div(5, 3, address_of(q), address_of(r));
  // q and r now contain quotient and rest
}
