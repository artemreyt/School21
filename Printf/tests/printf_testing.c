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
	int res = ft_printf("%8hhu", 255);
	printf("\n%d\n", res);
	return 0;
}
