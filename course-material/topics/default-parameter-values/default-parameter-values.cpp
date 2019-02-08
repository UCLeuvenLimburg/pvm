file open_file( const std::string& filename,
                bool writeable = true,
                bool createIfMissing = true );

open_file(fn, false);
// is same as
open_file(fn, false, true);

open_file(fn);
// is same as
open_file(fn, true, true);
