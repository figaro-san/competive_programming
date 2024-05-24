#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec.at(i);
	}

	/* ソート */
	sort(vec.begin(), vec.end());

	/* 重複を削除し、要素数は変わらないため、削除された重複分の容量を削除 */
	vec.erase(unique(vec.begin(), vec.end()), vec.end()); 

	cout << vec.size() <<endl;
}
