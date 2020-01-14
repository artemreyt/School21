#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <limits.h>

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
	// ft_printf("%-010dend\n", 332429);
	long double ld = -123.499923434;
	ft_printf("%# -23.10Lff\n", ld);
	printf("%# -23.10Lff\n", ld);
	return 0;
}
