#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		long long L, t, N, C;
		cin >> L >> t >> N >> C;
		vector<long long> a(C);
		for (int i = 0; i < C; ++ i) cin >> a[i];
		
		vector<long long> b(N+1);
		for (int i = 0; i < N; ++ i) {
			b[i+1] = b[i] + a[i%C]*2;
		}
		long long r = b.back();
		if (L >= 1) {
			long long x = 0;
			for (int j = 0; j < N; ++ j) {
				if (b[j] >= t) {
					x = max(x, a[j%C]);
				} else if (t-b[j] < a[j%C]*2) {
					x = max(x, a[j%C] - (t-b[j])/2);
				}
			}
			r = min(r, b.back() - x);
		}
		if (L >= 2) {
			long long x = 0;
			for (int j = 0; j < N; ++ j) {
				long long z = 0;
				if (b[j] >= t) {
					z = a[j%C];
				} else if (t-b[j] < a[j%C]*2) {
					z = a[j%C] - (t-b[j])/2;
				}
				for (int k = j+1; k < N; ++ k) {
					if (b[k]-z >= t) {
						x = max(x, z + a[k%C]);
					} else if (t-(b[k]-z) < a[k%C]*2) {
						x = max(x, z + a[k%C] - (t-(b[k]-z))/2);
					} else {
						x = max(x, z);
					}
				}
			}
			r = min(r, b.back() - x);
		}
		cout << "Case #"<<tt<<": " << r << endl;
	}
}
