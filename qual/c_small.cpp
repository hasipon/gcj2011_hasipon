#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> C;
void func() {
	int r = -1;
	for (int i = 1; i < (1<<N)-1; ++ i) {
		int x = 0, y = 0, a = 0, b = 0;
		for (int j = 0; j < N; ++ j) {
			if ((i>>j)&1) {
				x ^= C[j];
				a += C[j];
			} else {
				y ^= C[j];
				b += C[j];
			}
		}
		if (x == y) {
			r = max(r, max(a, b));
		}
	}
	if (r < 0) {
		cout << "NO" << endl;
	} else {
		cout << r << endl;
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++ t) {
		cin >> N;
		C = vector<int>(N);
		for (int i = 0; i < N; ++ i) cin >> C[i];
		cout << "Case #" << t << ": ";
		func();
	}
}