#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int D;
int num;
int pos[1000000];

bool check(double d) {
	double x = pos[0]-d;
	for (int i = 1; i < num; ++ i) {
		x = max(x+D, pos[i]-d);
		if (pos[i]+d < x) return false;
	}
	return true;
}

double func() {
	if (check(0)) return 0;
	double a = 0, b = 1e+30;
	while (b/a >= 1+1e-7) {
		double c = (b+a)/2;
		if (check(c)) {
			b = c;
		} else {
			a = c;
		}
	}
	return b;
}

int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		int C;
		cin >> C >> D;
		num = 0;
		for (int i = 0; i < C; ++ i) {
			int P, V;
			cin >> P >> V;
			for (int j = 0; j < V; ++ j) pos[num++] = P;
		}
		printf("Case #%d: %.7f\n", tt, func());
	}
}
