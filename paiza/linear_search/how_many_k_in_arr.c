#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tokenizer(char *not_tokenized_str, int *tokenized_str) {
	char *tok;
	int total_elements;


	tok = strtok(not_tokenized_str, " ");
	for (total_elements = 0; tok; ) {
		tokenized_str[total_elements] = atoi(tok);
		tok = strtok(NULL, " ");
		total_elements++;
	}

	return total_elements;
}

int main(void) {
	char str[10000];
	int tokenized_str[10000];
	int n, search_target, cnt=0;

	scanf("%d\n", &n);

	fgets(str, sizeof(str), stdin);
	int total_elements = tokenizer(str, tokenized_str);

	scanf("%d", &search_target);

	for (int i = 0; i < total_elements; i++) {
		if (search_target == tokenized_str[i]) {
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}
