int* a = stacknew int[4];
double* b = stacknew double[3];
bool* c = stacknew bool[4];
char* d = stacknew char[12];

// Cannot be freed in different order
free d;
free c;
free b;
free a;
