#include <stdio.h>
#include <malloc.h>

typedef struct {
	int winner;
	int loser;
} log;

int main(void) {
	int total_people, total_logs;
	log rps_logs[1000];

	scanf("%d %d", &total_people, &total_logs);


	for (int i = 0; i < total_logs; i++) {
		scanf("%d %d", &rps_logs[i].winner, &rps_logs[i].loser);
	}

	for (int i = 0; i < total_logs; i++) {
		printf("[debug] %d %d", rps_logs[i].winner, rps_logs[i].loser);
	}

	


	return 0;
}
