// 間違いあり
#include <stdio.h>

typedef struct {
	int start;
	int end;
} job_schedule;

int main(void) {
	int total_jobs;
	int job_start, job_end;

	scanf("%d", &total_jobs);
	job_schedule job_schedule[total_jobs];

	// startとendはその値を含む日数
	scanf("%d %d", &job_schedule[0].start, &job_schedule[0].end);
	int last_date = job_schedule[0].end;

	for (int i = 1; i < total_jobs; i++) {
		scanf("%d %d", &job_schedule[i].start, &job_schedule[i].end);
		if (last_date < job_schedule[i].end) {
			last_date = job_schedule[i].end;
		}
	}

	// 勤務する日付を1にする配列(インデックスは日付-1)
	// 0で初期化
	int job_schedule_arr[last_date];
	for (int i = 0; i < last_date; i++) {
		job_schedule_arr[i] = 0;
	}

	// 勤務する日付を1にする
	for (int i = 0; i < total_jobs; i++) {
		for(int j = job_schedule[i].start-1; j <= job_schedule[i].end-1; j++) {
			job_schedule_arr[j] = 1;
		}
	}

	int answer = 0;
	int working_days = 0;
	for(int i = 0; i < last_date; i++) {
		if (job_schedule_arr[i] == 1) {
			working_days += 1;

		}

		if (job_schedule_arr[i] == 0){
			//最も大きい(最も長い連勤日数)をanswerへ
			if(answer < working_days) {
				answer = working_days;
				working_days = 0;
			}
		}
	}

	if (answer < working_days) {
		answer = working_days;
	}
	

	printf("%d", answer);

	return 0;
}
