#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct {
	int index;
	int value;
} index_and_value;

index_and_value return_biggest(int argnum, ...) {
	va_list ap;
	va_start(ap, argnum);
	index_and_value max;
	max.index = va_arg(ap, int);
	max.value = va_arg(ap, int);

	index_and_value tmp;
	for (int i = 1; i < argnum/2; i++) {
		tmp.index = va_arg(ap, int);
		tmp.value = va_arg(ap, int);

		if (tmp.value > max.value) {
			max = tmp;
		}
	}

	va_end(ap);

	return max;

}

int main(void) {
	index_and_value answer = return_biggest(4, 1, 10, 2, 30);
	printf("index = %d, value = %d\n", answer.index, answer.value);
}
