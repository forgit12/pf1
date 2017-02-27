#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <locale.h>

#include "ft_printf.h"
#define S "%10d"
#define N 2345

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	write(1,"[ft] - [",8);
	printf("] - [%d]\n", ft_printf(S,N));
	printf("[pr] - [");
	printf("] - [%d]\n", printf(S,N));
}
