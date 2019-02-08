int find_password_index(const Person& person,
                        const std::string& password) {

  // p points to start of person
  const uint8_t* p = reinterpret_cast<const uint8_t*>(&person);

  // Scan person object
  for (int i = 0; i < sizeof(Person); ++i) {
    // __try: Windows-specific, to prevent crashes
    // to due illegal memory accesses
    __try {
      // Pretend p points to string
      const std::string* ps = reinterpret_cast<const std::string*>(p + i);

      // Check if we found the right spot
      if (*ps == password) return i;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
      // Do nothing in case of error
    }
  }
}
