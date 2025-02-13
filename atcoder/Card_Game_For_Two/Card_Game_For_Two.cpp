#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	int score_alice = 0, score_bob = 0;
	cin >> N;

	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec.at(i);
	}

	/* 降順ソート */
	sort(vec.rbegin(), vec.rend());

	for (int i = 0; i < N; i++) {
		if (i%2 == 0) {
			score_alice += vec.at(i);
		} else {
			score_bob += vec.at(i);
		}
	}

	cout << score_alice - score_bob << endl;
}
