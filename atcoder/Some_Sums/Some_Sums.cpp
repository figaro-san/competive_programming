#include <bits/stdc++.h>

using namespace std;

// 割り算がシフトで
// 剰余計算が桁の抜き出し
int sum_all_digits(int num) {
	int ans = 0;

	while (num != 0) {
		ans += num % 10;
		num /= 10;
	}

	return ans;
}

int main() {
	int N, A, B;
	int tmp, ans = 0;
	cin >> N >> A >> B;

	for (int i = 1; i <= N; i++) {
		tmp = sum_all_digits(i);
		if (A <= tmp && tmp <= B) {
			ans += i;
		}
	}

	cout << ans << endl;
}
