#include <stdio.h>
#include <stdarg.h>

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
	// printf("%20.f", 277221.4);
	// printf("%d\n", sum(3, 2, 9, 3));
	int res = printf("hello\0, world!");
	printf("\n%d\n", res);
	return 0;
}
