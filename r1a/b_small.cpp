#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int N, M;
string D[10000];
string L[100];
void func() {
	for (int i = 0; i < M; ++ i) {
		int p = 0;
		int m = -1;
		for (int j = 0; j < N; ++ j) {
			int c = 0;
			set<int> s;
			int len = D[j].length();
			for (int k = 0; k < N; ++ k) {
				if (D[k].length() == len) s.insert(k);
			}
			for (int kk = 0; kk < 26; ++ kk) {
				char cc = L[i][kk];
				bool f = false;
				for (set<int>::iterator l = s.begin(); l != s.end(); ++ l) {
					if (D[*l].find(cc) != string::npos) {
						f = true;
						break;
					}
				}
				if (f) {
					if (D[j].find(cc)==string::npos) ++ c;
					set<int> t;
					for (set<int>::iterator l = s.begin(); l != s.end(); ++ l) {
						bool f = true;
						for (int x = 0; x < len; ++ x) {
							if (
								(D[*l][x]==cc && D[j][x]!=cc) ||
								(D[*l][x]!=cc && D[j][x]==cc)
							) {
								f = false;
								break;
							}
						}
						if (f) t.insert(*l);
					}
					s = t;
				}
			}
			if (c > m) {
				p = j;
				m = c;
			}
		}
		cout << " " << D[p];
	}
	cout << endl;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++ t) {
		cin >> N >> M;
		for (int i = 0; i < N; ++ i) {
			cin >> D[i];
		}
		for (int i = 0; i < M; ++ i) {
			cin >> L[i];
		}
		cout << "Case #"<<t<<":";
		func();
	}
}