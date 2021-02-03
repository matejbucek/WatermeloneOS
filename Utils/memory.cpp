#include <Utils/memory.hh>
namespace Utils{
extern "C" {
    
void *memcpy(char* dst, const char *src, int n)
{
	char *p = dst;
	while (n--)
		*dst++ = *src++;
	return p;
}

void *memset(char* dst, int ch, int n)
{
	char *p = dst;
	while (n--)
		*dst++ = ch;
	return p;
}

void *memmvo(char *dst, char *src, int base, int until, int to){
	for(int i = base; i < until; i++){
		dst[to + (i-base)] = src[i];
	}
}

}
};
