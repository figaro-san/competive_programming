//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> // reverse
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>

#define _GLIBCXX_DEBUG //からのコンテナに対する操作がエラーになる

using namespace std;

void about_string() {
	string str1, str2; // intならcinで数字しか受け付けない, charなら1文字のみ
	cin >> str1;
	str2 = "mello";

	cout << str1 << str2 << endl;

	/* 文字長 */
	cout << str1.size() << endl;
	
	/* 部分取り出し(どちらも同じ) */
	cout << str1.at(1) << endl;
	cout << str1[1] << endl;

	/* 文字の置き換え */
	str1[0] = 'm'; // str1.at(1) = 'm'; でも可
	cout << str1 << endl;

	/* リテラルを扱うなら "XXX"s のように末尾にsを付けて利用 */
	cout << "Hello"s.size() << endl;

	/* 文字列比較 */
	if (str1 == str2) {
		cout << "str1 == str2" << endl;
	}

	/* 文字列連結 */
	cout << str1 + str2 << endl;
}

void about_arr() {
	vector<int> vec;
	vector<int> vec2(3); //vec = {0, 0, 0};
	vector<int> vec3(3, 5); // vec = {5, 5, 5};
	
	/* 配列を見る */
	vec = {25, 100, 64};
	cout << "before push_back()" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}


	/* push_back()で末尾に要素追加 */
	vec.push_back(-1);
	cout << "after push_bask()" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}


	/* pop_back()で末尾の要素を取り出し */
	vec.pop_back();
	cout << "after pop_bask()" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}


	/* 任意の数の入力受け取って、合計値を算出 */
	int N, sum = 0;
	vector<int> input_buff(N);

	cout << "how many input : ";
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input_buff[i];
		sum += input_buff[i];
	}

	cout << "sum is " << sum << endl;

}

void about_stl() {
	int a = 10, b = -1;

	int answer = min(a, b);
	cout << "min is " << answer << endl;

	answer = max(a, b);
	cout << "man is " << answer << endl;

	swap(a, b);
	cout << "after swap() : " << a << ", " << b << endl;

	/* 配列の反転 */
	vector<int> vec = {2, 3, 1, 10, 6};
	reverse(vec.begin(), vec.end());

	cout << "reversed vec" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}

	/* 配列のソート */
	sort(vec.begin(), vec.end());
	cout << "after sorted" << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << endl;
	}
}

void tmp(int &n, vector<int> &vec) {
	n = -1;
	vec[0] = -1;
}

void about_reference() {
	int n = 1;
	vector<int> vec = {1, 1};
	tmp(n, vec);

	cout << "after called func" << endl;
	cout << n << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}

void about_loop() {
	int a;
	cin >> a;
	int counter = 0;
	vector <int> data(5);

	for (int i : data) {
		cin >> data.at(i);
		if (data.at(i) == a) {
			counter++;
		}
	}

	cout << "answer is : " << counter << endl;
}

void multi_arr() {
	vector<vector<int>> data = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
	};
}

void pair_tuple_auto() {
	/* pair型変数の作成 */
	pair<string, int> p("abc", 4);
	cout << p.first << ", " << p.second << endl;
	
	/* 上書き */
	p = make_pair("*", 1);
	cout << p.first << ", " << p.second << endl;

	/* tie()で分割 */
	string s;
	int a;
	tie(s, a) = p;



	/* tuple */
	tuple<int, string, bool> data(1, "hello", true);

	/* tupleへのアクセス(2は定数なので変数ではだめ) */
	get<2>(data) = false;

	/* 上書き */
	data = make_tuple(2, "world", false);

	/* tie()で分割 */
	bool b;
	tie(a, s, b) = data;



	/* autoは型推論 */
	vector<int> d = {-1, -2, -3};
	for (auto elem : d) {
		cout << elem << endl;
	}

}

void about_map() {
	/* map<key, value> */
	map<string, int> data;

	/* 追加 */
	data["alice"] = 10;
	data["bob"] = 9;
	data["charlie"] = 8;

	/* 削除 */
	data.erase("alice");

	/* アクセス */
	//data.at("alice");
	data["taro"]; // taroが存在しない時、[]でアクセスしたら追加される

	/* keyに対応するvalueが存在するか */
	if (data.count("alice")) {
		cout << "alice is here" << endl;
	} else if (data.count("taro")) {
		cout << "taro is here" << endl;
	}

	/* 要素数 */
	data.size();

	for (auto elem : data) {
		auto a = elem.first;
		auto b = elem.second;
		cout << a << " => " << b << endl;
	}
}

void about_queue() {

	/* 先入れ先出し */
	queue<int> q;
	q.push(10);
	q.push(3);
	q.push(1);

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}

	/* 大きいものから出す */
	priority_queue<int> pq;
	pq.push(10);
	pq.push(3);
	pq.push(1);
	pq.push(11);

	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

	/* 小さいものから取り出す */
	priority_queue<int, vector<int>, greater<int>> pqmin;
	pqmin.push(10);
	pqmin.push(3);
	pqmin.push(1);
	pqmin.push(11);

	while (!pqmin.empty()) {
		cout << pqmin.top() << endl;
		pqmin.pop();
	}


}

void about_set() {
	/* setは重複のないデータのまとまりを扱うためのデータ構造 */
	/* keyだけのmap */
	set<int> S;
	S.insert(3);
	S.insert(10);
	S.insert(4);
	S.insert(8);

	cout << "size = " << S.size() << endl;

	/* 7が含まれるか */
	if (S.count(7)) {
		cout << "found 7" << endl;
	}

	/* 値の削除 */
	S.erase(10);

	/* 空かどうか */
	if (S.empty()) {
		cout << "S is empty" << endl;
		return;
	}

	/* 最小値の取得 */
	cout << "mix value = " << *begin(S) << endl;

	/* 最大値の取得 */
	cout << "max value = " << *rbegin(S) << endl;

	/* 小さい順になる */
	for (auto value : S) {
		cout << value << endl;
	}
}

void about_stack() {
	stack<int> s;
	s.push(10);
	s.push(1);
	s.push(3);

	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	cout << s.size() << endl;

	if (s.empty()) {
		cout << "s is empty" << endl;
	}
}

void about_deque() {
	/* スタックとキューの操作を行えるデータ構造 */
	deque<int> d;
	d.push_back(10);
	d.push_back(1);
	d.push_back(2);
	/* {10, 1, 2} */

	cout << d.front() << ", " << d.back() << endl;

	d.pop_front();
	d.pop_back();
	d.push_front(-1);
	d.push_back(-2);
	/* {-1, 1, -2} */

	cout << d.at(1) << endl;
	/* sizeとemptyもある */

}

void about_unorderred_map() {
	/* 制約があるがmapより高速なmap */
	/* 取り出すときに、どの順番で取り出されるか分からない */
	unordered_map<int, string> test;

	/* unordered_setもある */
	/* 最大値、最小値を取り出せない、どの順番かも分からない */
}

void about_lower_apper_bound() {
	/* 昇順ソートされた配列で、x以上の最小・最大の要素を求める */
	vector<int> a = {0, 4, 5, 8, 10, 20};
	cout << *lower_bound(a.begin(), a.end(), 12) << endl;
}

int main() {
	/* 1章 */
	//about_string();
	//about_arr();
	//about_stl();
	//about_reference();
	
	/* 2章 */
	//about_loop();
	
	//about_map();
	//about_queue();
	//about_set();
	//about_stack();
	about_lower_apper_bound();
}

