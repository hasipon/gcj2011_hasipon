#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N, M;
int c[80], s[80], t[80];

int func() {
	int ret2 = 0;
	for (int k = 0; k <= M; ++ k) {
		bool used[80] = {0};
		int ret = 0;
		int p = 0;
		int T = 1;
		while (T > 0) {
			for (int i = 0; i < N+p; ++ i) {
				if (!used[i] && t[i] > 0) {
					T += t[i]-1;
					p = min(M, p+c[i]);
					used[i] = true;
					ret += s[i];
				}
			}
			if (p < k) {
				int sel = -1;
				for (int i = 0; i < N+p; ++ i) {
					if (!used[i] && c[i] > 0) {
						if (sel < 0 || s[i] > s[sel]) sel = i;
					}
				}
				if (sel >= 0) {
					p = min(M, p+c[sel]);
					used[sel] = true;
					ret += s[sel];
					-- T;
				} else {
					for (int i = 0; i < N+p; ++ i) {
						if (!used[i]) {
							if (sel < 0 || s[i] > s[sel]) sel = i;
						}
					}
					if (sel >= 0) {
						used[sel] = true;
						ret += s[sel];
						-- T;
					} else {
						break;
					}
				}
			} else {
				int sel = -1;
				for (int i = 0; i < N+p; ++ i) {
					if (!used[i]) {
						if (sel < 0 || s[i] > s[sel]) sel = i;
					}
				}
				if (sel >= 0) {
					used[sel] = true;
					ret += s[sel];
					-- T;
				} else {
					break;
				}
			}
		}
		ret2 = max(ret2, ret);
	}
	return ret2;
}
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		cin >> N;
		for (int i = 0; i < N; ++ i) {
			cin >> c[i] >> s[i] >> t[i];
		}
		cin >> M;
		for (int i = 0; i < M; ++ i) {
			cin >> c[i+N] >> s[i+N] >> t[i+N];
		}
		cout << "Case #"<<tt<<": " << func() << endl;
	}
}