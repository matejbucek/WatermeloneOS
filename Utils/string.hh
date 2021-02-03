#pragma once
#include <Utils/memory.hh>
#include <Utils/types.hh>
namespace Utils{
class String{
    char * str;
public: 
    ~String() = default;
    String() = default;
    String(const char* text);
    String operator=(const char * text) const{
        return String(text);
    }
    char * getChars();
};

extern "C"
{
    int strlen(const char *s);
    char *strncpy(char *destString, const char *sourceString, int maxLength);
    int strcmp(const char *dst, const char *src);
    char* strcpy(char *dst,const char *src);
    void strcat(char *dest,const char *src);
    int strncmp( const char* s1, const char* s2, int c );
};
};
