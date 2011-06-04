#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		int X, S, R, t, N;
		cin >> X >> S >> R >> t >> N;
		vector<int> B(N), E(N), w(N);
		for (int i = 0; i < N; ++ i) {
			cin >> B[i] >> E[i] >> w[i];
		}
		int x = X;
		vector<pair<int,int> > a;
		for (int i = 0; i < N; ++ i) {
			a.push_back(make_pair(S+w[i], E[i]-B[i]));
			x -= E[i]-B[i];
		}
		a.push_back(make_pair(S, x));
		sort(a.begin(), a.end());
		double r = 0;
		double rt = t;
		for (int i = 0; i < a.size(); ++ i) {
			double dist = a[i].second;
			double speed0 = a[i].first;
			double speed1 = a[i].first + (R-S);
			double t1 = min(dist / speed1, rt);
			double dist1 = t1 * speed1;
			double dist0 = dist - dist1;
			r += dist0 / speed0;
			r += dist1 / speed1;
			rt -= t1;
		}
		printf("Case #%d: %f\n", tt, r);
	}
}
