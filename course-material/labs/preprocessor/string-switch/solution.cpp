#define SWITCH_STRING(string) auto _switch_string_ = string;
#define STRING_CASE(case)     if ( _switch_string_ == #case )
#define STRING_ELSE           else
