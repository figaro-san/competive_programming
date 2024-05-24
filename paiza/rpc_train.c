#include <stdio.h>
#include <malloc.h>

typedef struct {
	int top;
	int total_member;
} train_state;

int main(void) {
	int total_people, total_logs;
	int winner, loser;

	scanf("%d %d", &total_people, &total_logs);
	train_state train_state[total_people];

	// 初期化
	for (int i = 0; i < total_people; i++) {
		train_state[i].top = i;
		train_state[i].total_member = 1;
	}

	// winnerの列車の人数に、loserの列車の人数を足し合わせる
	for (int i = 0; i < total_logs; i++) {
		scanf("%d %d", &winner, &loser);
		train_state[winner-1].total_member += train_state[loser-1].total_member;
	}

	//最終的に一番total_memberが大きいtopが出力
	int biggest_total_member = train_state[0].total_member;
	for (int i = 1; i < total_people; i++) {
		if (train_state[i].total_member > biggest_total_member) {
			biggest_total_member = train_state[i].total_member;
		}	
	}

	// biggest_total_memberと等しい列車の先頭(勝者)を出力
	for (int i = 0; i < total_people; i++) {
		if (train_state[i].total_member == biggest_total_member) {
			printf("%d\n", train_state[i].top + 1);
		}
	}

	return 0;
}
