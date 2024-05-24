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

void print_matrix(int *matrix, int h, int w) {
	int i, j;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			printf("%d ", *matrix);
			matrix++;
		}
		puts("");
	}

}

int main(void) {
	int h, w;
	int i, j, k;
	char str[10000];
	char *tok;
	index_and_value max;

	scanf("%d %d\n", &h, &w);

	int point_matrix[h][w];

	for (i = 0; i < h; i ++) {
		fgets(str, sizeof(str), stdin);
		tok = strtok(str, " ");
		for (j = 0; tok; ) {
			point_matrix[i][j] = atoi(tok);
			tok = strtok(NULL, " ");
			j++;
		}
	}
	//print_matrix(*point_matrix, h, w);

	int answer = 0;
	int tmp = 0;
	int copy_i;

	// point_matrix[j][i]
	for (i = 0; i < w; i++) {
		copy_i = i;
		tmp += point_matrix[0][i];

		for (j = 1; j < h; j++) {
			// 右端
			if (copy_i == w-1) {
				max = return_biggest(4, copy_i-1, point_matrix[j][copy_i-1], copy_i, point_matrix[j][copy_i]);
			}

			// 左端
			else if (copy_i == 0) {
				max = return_biggest(4, copy_i, point_matrix[j][copy_i], copy_i+1, point_matrix[j][copy_i+1]);
			}

			// それ以外
			else {
				max = return_biggest(6, copy_i-1, point_matrix[j][copy_i-1], copy_i, point_matrix[j][copy_i], copy_i+1, point_matrix[j][copy_i+1]);
			}

			tmp += max.value;
			copy_i = max.index;
		}
		if (answer < tmp) {
			answer = tmp;
		}

		tmp = 0;
	}
	printf("%d", answer);

	return 0;
}
