#include <iostream>
#include <vector>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		int N, L, H;
		cin >> N >> L >> H;
		vector<int> a(N);
		for (int i = 0; i < N; ++ i) cin >> a[i];
		cout << "Case #"<<tt<<": ";
		for (int i = L; i <= H; ++ i) {
			bool f = true;
			for (int j = 0; j < N; ++ j) {
				if (a[j] % i != 0 && i % a[j] != 0) {
					f = false;
					break;
				}
			}
			if (f) {
				cout << i << endl;
				goto next;
			}
		}
		cout << "NO" << endl;
		next:;
	}
}