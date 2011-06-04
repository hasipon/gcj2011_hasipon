#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int R, C, D;
vector<string> w;
void func() {
	for (int size = min(R, C); size >= 3; -- size) {
		for (int i = 0; i+size <= R; ++ i) {
			for (int j = 0; j+size <= C; ++ j) {
				double sx = 0, sy = 0;
				for (int k = 0; k < size; ++ k) {
					int l0 = 0, l1 = size;
					if (k == 0 || k == size-1) {
						l0 = 1; l1 = size-1;
					}
					for (int l = l0; l < l1; ++ l) {
						sx += (2*k - (size-1)) * (w[i+k][j+l]-'0');
						sy += (2*l - (size-1)) * (w[i+k][j+l]-'0');
					}
				}
				if (sx == 0 && sy == 0) {
					cout << size;
					return;
				}
			}
		}
	}
	cout << "IMPOSSIBLE";
}
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		cin >> R >> C >> D;
		w = vector<string>(R);
		for (int i = 0; i < R; ++ i) cin >> w[i];
		cout << "Case #"<<tt<<": ";
		func();
		cout << endl;
	}
}
