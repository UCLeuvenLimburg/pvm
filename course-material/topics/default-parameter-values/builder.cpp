class open_file
{
public:
  builder& writeable(bool b) { ... }
  builder& createIfMissing(bool b) { ... }

  file finish();
};

file f = open_file().writeable(true).finish();
