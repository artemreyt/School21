#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int sum(int n, ...) {
	int result = 0;
	va_list args;
	va_start(args, n);

	while (n--) {
		result += va_arg(args, int);
	}
	va_end(args);
	return result;
}

int main() {
	ft_printf("%#.4x", 39);
	// printf("%#.4x", 39);
	return 0;
}
