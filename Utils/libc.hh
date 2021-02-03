#pragma once

#include <Utils/types.hh>
#include <stdarg.h>
#include <Utils/memory.hh>
#include <Utils/string.hh>
#include <Utils/io.hh>
namespace Utils{
extern "C" {
	void 	itoa(char *buf, unsigned long int n, int base);
}
};
