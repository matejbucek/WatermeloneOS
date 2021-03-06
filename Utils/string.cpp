#include "string.hh"

namespace Utils{
char* String::getChars(){
    return this->str;
}

String::String(const char* text){
    this->str = (char*)text;
}

int strlen(const char *s){
    int i = 0;
    while(*s++){
        i++;
    }
    return i;
}

int strcmp(const char *dst, const char *src){
    int i = 0;
    while (dst[i] == src[i]){
        if(src[i++] == 0)
            return 0;
    }
    return 1;
}

char* strcpy(char *dst,const char *src){
    int i = 0;
    while(dst[i] = src[i++]);
    return dst;
}

void strcat(char *dest,const char *src)
	{
		if(*dest){
			strcat(++dest, src);
		}else{
			if(*dest++ = *src++){
				strcat(dest, src);
			}
		}
	}
	

	int strncmp( const char* s1, const char* s2, int c ) {
		int result = 0;

		while ( c ) {
			result = *s1 - *s2++;

			if ( ( result != 0 ) || ( *s1++ == 0 ) ) {
				break;
			}

			c--;
		}

		return result;
	}

    char *strncpy(char *destString, const char *sourceString,int maxLength)
	{
	  unsigned count;

	  if ((destString == (char *) NULL) || (sourceString == (char *) NULL))
		{
		  return (destString = NULL);
		}

	  if (maxLength > 255)
		maxLength = 255;

	  for (count = 0; (int)count < (int)maxLength; count ++)
		{
		  destString[count] = sourceString[count];
		  
		  if (sourceString[count] == '\0')
		break;
		}

	  if (count >= 255)
		{
		  return (destString = NULL);
		}

	  return (destString);
	}
};
