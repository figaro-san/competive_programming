#include <stdio.h>

int main(void) {
	int people_count, x, y;

	scanf("%d %d %d", &people_count, &x, &y);

	for(int i = 1; i <= people_count; i ++) {

		if ((i % x) == 0) {
			printf("A");
		}

		if ((i % y) == 0) {
			printf("B");
		}

		if (((i % y) != 0) && ((i % x) != 0)) {
			printf("N");
		}

		printf("\n");
	}
	return 0;
}
