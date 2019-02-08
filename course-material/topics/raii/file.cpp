int read_from_file(std::string path)
{
  // Open file
  std::ifstream file(path);

  // Read data from file (same as std::cin)
  int x;
  file >> x;

  // Return read data
  return x;

  // file goes out of scope
  // destructor closes file automatically
}
