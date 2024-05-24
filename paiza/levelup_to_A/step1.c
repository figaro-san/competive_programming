#include <stdio.h>

#define NUM 20
typedef char matrix[NUM][NUM];

void parcer(char curr_str[20], matrix matrix, int i, int W) {
	//printf("curr_str = %s", curr_str);
	for (int j = 0; j < W; j++) {
		matrix[i][j] = curr_str[j];
	}
	
}

void disp_matrix(matrix matrix, int H, int W) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			printf("%c " , matrix[i][j]);
		}
		puts("");
	}
}

int main(void) {
	int H, W, N;
	char dummy;
	char curr_str[20];
	int X[400], Y[400];
	matrix matrix;

	scanf("%d %d %d", &H, &W, &N);
	scanf("%c", &dummy);

	for (int i = 0; i < H; i++) {
		fgets(curr_str, sizeof(curr_str), stdin);
		parcer(curr_str, matrix, i, W);
		//printf("cnt = %d, input = %s\n", i, curr_str);
	}

	//disp_matrix(matrix, H, W);
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &X[i], &Y[i]);
	}

	for (int i = 0; i < N; i++) {
		printf("%c\n", matrix[X[i]][Y[i]]);
	}

	return 0;
}
