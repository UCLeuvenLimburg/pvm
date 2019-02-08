// Not real C++ syntax
int x;
address_of_int ax = address_of(x);

x = 5;
// is equivalent with
write_int_to_address(ax, 5);
