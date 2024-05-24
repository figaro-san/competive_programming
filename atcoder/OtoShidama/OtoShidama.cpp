#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)

int main(void) {
	int N, Y, k;
	cin >> N >> Y;

	rep(i, 0, N+1) {
		rep(j, 0, N+1) {
			k = N - (i+j);
			if (0 <= k) {
				if (10000*i + 5000*j + 1000*k == Y) {
					cout << i << " " << j << " " << " " << k;
					return 0;
				}
			}
		}
	}

	cout << "-1 -1 -1" << endl;
}

/*
 * 肝はN^3じゃなくてN^2にとりあえず抑えたこと。
 * 10000と5000の枚数を全探索すれば、1000の枚数はそれぞれ一意に決まる。
 */
