#ifndef EXPORT_H
#define EXPORT_H

#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT __attribute__((visibility("default")))
#endif

#endif // EXPORT_H