#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> vec(N);

	for (int i = 0; i < N; i++) {
		cin >> vec.at(i);
	}

	for (int i = 0; i < N; i++) {
		cout << vec.at(i) << endl;
	}
}

/*
 * C++においては、空白も改行も同じ区切り文字として扱われるため、
 * 5
 * 1 2 3 4 5
 * でも
 * 5
 * 1
 * 2
 * 3
 * 4
 * 5
 * でも良い
 */
