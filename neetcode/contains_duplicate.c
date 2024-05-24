#include <stdbool.h>
#include <stdlib.h>

int cmp (const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) {
	qsort(nums, numsSize, sizeof(int), cmp);

	for (int i = 1; i < numsSize; i++) {
		if (nums[i] == nums[i-1]) {
			return true;
		}
	}

	return false;
}

/*
 * 配列中の重複を探す
 * ソートすれば重複が連続するようになるので、あとは前後を比較して重複があればfalseを返す
 */
