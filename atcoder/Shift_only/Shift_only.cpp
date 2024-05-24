#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, cnt = 0;
	cin >> N;

	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec.at(i);
	}


	while (true) {
		for (int i = 0; i < N; i++) {
			if (vec.at(i) == 0 or vec.at(i) % 2 != 0) {
				//cout << cnt << endl;
				goto result;
			}
			vec.at(i) /= 2;
		}
		cnt++;
	}

result:
	cout << cnt << endl;
}
