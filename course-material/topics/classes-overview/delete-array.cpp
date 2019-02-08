T* ts = new T[10];

// ...

delete[] ts; // 10 destructors get called
