#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
	int slen = strlen(s);
	int tlen = strlen(t);

	int alphabet_cnt[26] = {0};

	if (slen != tlen) {
		return false;
	}

	for (int i = 0; i < slen; i++) {
		alphabet_cnt[s[i] - 97]++;
	}

	for (int i = 0; i < tlen; i++) {
		alphabet_cnt[t[i] - 97]--;
	}

	for (int i = 0; i < 26; i++) {
		if (alphabet_cnt[i] != 0) {
			return false;
		}
	}

	return true;
}

/*
 * アナグラムを見つけるもの
 * ２つの文字列が渡され、それがアナグラムかどうか判定する
 * 具体的にはアルファベット全てを意味する配列を用意し、
 * 片方のアルファベットに関して、アルファベット- 97(文字から数字への変換)を全ての文字に行い、
 * 該当するアルファベット配列の場所にに、その個数をカウントする
 *
 * 反対にもう片方は該当するアルファベットが存在した場合、そのアルファベット配列からカウントを引く。
 * こうすることで配列中に0以外が存在した時、アナグラムではない(アナグラムなら両方に出現する文字は
 * 必ず同じ文字が同じ個数現れるため)
 *
 */
