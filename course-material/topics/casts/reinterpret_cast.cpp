Cat* cat = new Cat;
Cow* cow = reinterpret_cast<Cow*>(cat);

// Ben Stiller is vindicated
cow->milk();

// Anything goes
int* ns = reinterpret_cast<int*>(cow);
