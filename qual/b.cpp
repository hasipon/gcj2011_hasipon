#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int C, D, N;
vector<string> combine, opposed;
string element;
void func() {
	string list;
	for (int i = 0; i < N; ++ i) {
		list += element[i];
		if (list.length() >= 2) {
			string x = list.substr(list.length()-2);
			string y = x;
			swap(y[0], y[1]);
			for (int j = 0; j < C; ++ j) {
				string s = combine[j].substr(0,2);
				if (x == s || y == s) {
					list.erase(list.begin()+list.length()-1);
					list[list.length()-1] = combine[j][2];
				}
			}
		}
		for (int j = 0; j < D; ++ j) {
			bool a[2] = {false, false};
			for (unsigned k = 0; k < list.length(); ++ k) {
				if (!a[0] && list[k] == opposed[j][0]) a[0] = true;
				else if (!a[1] && list[k] == opposed[j][1]) a[1] = true;
			}
			if (a[0] && a[1]) list = "";
		}
	}
	for (unsigned i = 0; i < list.length(); ++ i) {
		if (i) cout << ", ";
		cout << list[i];
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++ t) {
		cin >> C;
		combine = vector<string>(C);
		for (int i = 0; i < C; ++ i) cin >> combine[i];
		cin >> D;
		opposed = vector<string>(D);
		for (int i = 0; i < D; ++ i) cin >> opposed[i];
		cin >> N;
		cin >> element;
		cout << "Case #" << t << ": [";
		func();
		cout << "]" << endl;
	}
}