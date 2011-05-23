#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++ t) {
		int R, C;
		cin >> R >> C;
		vector<string> a(R);
		for (int i = 0; i < a.size(); ++ i) cin >> a[i];
		cout << "Case #"<<t<<":" << endl;
		bool f = true;
		for (int i = 0; i < R-1; ++ i) {
			for (int j = 0; j < C-1; ++ j) {
				if (a[i][j] == '#') {
					if (a[i][j+1] == '.') goto last;
					if (a[i+1][j] == '.') goto last;
					if (a[i+1][j+1] == '.') goto last;
					a[i][j] = a[i+1][j+1] = '/';
					a[i][j+1] = a[i+1][j] = '\\';
				}
			}
		}
		for (int i = 0; i < R; ++ i) {
			for (int j = 0; j < C; ++ j) {
				if (a[i][j] == '#') goto last;
			}
		}
		f = false;
	last:
		if (f) {
			cout << "Impossible" << endl;
		} else {
			for (int i = 0; i < a.size(); ++ i) cout << a[i] << endl;
		}
	}
}
