#include <stdio.h>

void tokenizer() {

}

int main(void) {
	int H;
	char buff[10][5];
	char dummy;

	char str[6]; // \0が入るため
	char **matrix;

	scanf("%d", &H);
	scanf("%c", &dummy);

	for (int i = 0; i < H; i++) {
		fgets(str, sizeof(str), stdin);
		matrix[i] = str;
	}

	printf("%s", *matrix);

	return 0;
}
