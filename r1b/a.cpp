#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		int N;
		cin >> N;
		vector<string> a(N);
		for (int i = 0; i < N; ++ i) cin >> a[i];
		vector<int> win(N);
		vector<int> play(N);
		vector<double> WP(N);
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < N; ++ j) {
				if (a[i][j] != '.') {
					if (a[i][j] == '1') ++ win[i];
					++ play[i];
				}
			}
			WP[i] = (double)win[i] / play[i];
		}
		vector<double> OWP(N);
		for (int i = 0; i < N; ++ i) {
			double x = 0, y = 0;
			for (int j = 0; j < N; ++ j) {
				if (a[i][j] == '0') {
					x += (double)(win[j]-1) / (play[j]-1);
					++ y;
				} else if (a[i][j] == '1') {
					x += (double)win[j] / (play[j]-1);
					++ y;
				}
			}
			OWP[i] = (double)x / y;
		}
		vector<double> OOWP(N);
		for (int i = 0; i < N; ++ i) {
			double x = 0, y = 0;
			for (int j = 0; j < N; ++ j) {
				if (a[i][j] != '.') {
					x += OWP[j];
					++ y;
				}
			}
			OOWP[i] = x / y;
		}
		printf("Case #%d:\n", tt);
		for (int i = 0; i < N; ++ i) {
			printf("%.10f\n", WP[i]/4 + OWP[i]/2 + OOWP[i]/4);
		}
	}
}
