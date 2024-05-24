#include <stdio.h>
int main(void) {
	char str[1000];
	
	fgets(str, sizeof(str), stdin);
	printf("%s\n", str);

	return 0;
}
