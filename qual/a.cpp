#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int func(vector<string> R, vector<int> P) {
	int o = 1, b = 1;
	int to = 0, tb = 0, t = 0;
	for (unsigned i = 0; i < R.size(); ++ i) {
		if (R[i] == "O") {
			int d = abs(P[i] - o);
			o = P[i];
			to = max(t, to+d)+1;
			t = to;
		} else {
			int d = abs(P[i] - b);
			b = P[i];
			tb = max(t, tb+d)+1;
			t = tb;
		}
	}
	return t;
}
int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++ i) {
		int N;
		cin >> N;
		vector<string> R(N);
		vector<int> P(N);
		for (int j = 0; j < N; ++ j) {
			cin >> R[j] >> P[j];
		}
		cout << "Case #" << i << ": " << func(R, P) << endl;
	}
}
