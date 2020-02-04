#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <limits.h>
#include <math.h>

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
	int a;
	int *ptr = &a;
	// ft_printf("% 12s\n%-4.c% #p\n%#lf\n% d\n", "string", 'a', ptr, sqrt(-1), 21);
	// printf("% 12s\n%-4.c% #p\n%#lf\n% d\n", "string", 'a', ptr, sqrt(-1), 21);
	// ft_printf("%jx", 4294967295);
	// printf("%jx", 429493295);

	// ft_printf("%.0p, %.p\n", 0, 0);
	// printf("%.0p, %p", 0, 0);
	// ft_printf("%2c", 0);
	// int n1 = ft_printf("{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);
	// int n2 = printf("{%f}{%lf}{%Lf}\n", 1.42, 1.42, 1.42l);

	// int n1 = ft_printf("%");
	// printf("\n");
	// int n2 = printf("%");
	// printf("\n%d %d", n1, n2);

	ft_printf("%.0p, %.p\n", 1, 1);
	printf("%.0p, %.p", 1, 1);

	// ft_printf("%.0p, %.p\n", 0, 0);
	// printf("%.0p, %.p\n", 0, 0);

	return 0;
}
