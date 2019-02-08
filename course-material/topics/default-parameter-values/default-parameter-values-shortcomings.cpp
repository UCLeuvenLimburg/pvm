file open_file( const std::string& filename,
                bool writeable = true,
                bool createIfMissing = true );

// Intention: open writeable file,
// but do not create if missing
open_file(fn, false);
// but this is interpreted as
open_file(fn, false, true);
// and I want
open_file(fn, true, false);
