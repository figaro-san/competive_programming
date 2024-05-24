#include <bits/stdc++.h>

using namespace std;

int main() {
	string buff;
	cin >> buff;
	int cnt = 0;

	//cout << buff << endl;
	
	for (int i = 0; i < 3; i++) {
		if (buff[i] == '1') {
			cnt++;
		}
	}

	cout << cnt << endl;
}
