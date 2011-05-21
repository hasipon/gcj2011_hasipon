#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int N;
vector<int> C;
void func() {
	int x = 0;
	for (int i = 0; i < N; ++ i) {
		x ^= C[i];
	}
	if (x == 0) {
		int r = accumulate(C.begin(), C.end(), 0);
		r -= *min_element(C.begin(), C.end());
		cout << r << endl;
	} else {
		cout << "NO" << endl;
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