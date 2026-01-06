#ifndef STUB_HPP
#define STUB_HPP

#ifdef _MSC_VER
    #define STUB_WARN(msg) __pragma(message(msg))
#else
    // _Pragma requires a string literal
    #define STR_PRAGMA(x) _Pragma(#x)
    #define STUB_WARN(msg) STR_PRAGMA(message("STUB: " msg))
#endif

// Macro to mark unimplemented functions
// - ret_type: return type of the function
// - msg: descriptive message to show at compile-time
// - sentinel: safe value to return (false, 0, nullptr, etc.)
#define STUB_RETURN(ret_type, msg, sentinel) \
    do { \
        STUB_WARN(msg); \
        return (ret_type)(sentinel); \
    } while(0)

#endif // STUB_HPP