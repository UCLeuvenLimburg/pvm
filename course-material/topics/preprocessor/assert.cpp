#ifdef DEBUGGING
#define assert(c) \
  if ( !c ) \
    abort( #c " failed", __LINE__, __FILE__ )
#else
#define assert(c)
#endif
