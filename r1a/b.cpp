#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int N, M;
string D[10000];
string L[100];
set<int> hoge[11];
int piyo[26][10000];
int fuga[10000];
int p, m, idx;

void f(int s, int cc, const set<int>& a) {
	if (a.empty()) return;
	if (a.size() == 1) {
		//cerr << ":" << D[*hoge[len].begin()] << " " << 0 << endl;
		if (s > m) {
			p = *a.begin();
			m = s;
		} else if (s == m) {
			p = min(p, *a.begin());
		}
	} else {
		int h = 0;
		for (set<int>::iterator k = a.begin(); k != a.end(); ++ k) {
			h |= fuga[*k];
		}
		for (;; ++ cc) {
			if ((h>>(L[idx][cc]-'a'))&1) break;
		}
		char c = L[idx][cc];
		map<int, set<int> > b;
		for (set<int>::iterator k = a.begin(); k != a.end(); ++ k) {
			b[ piyo[c-'a'][*k] ].insert(*k);
		}
		for (map<int, set<int> >::iterator k = b.begin(); k != b.end(); ++ k) {
			f(s + (k->first==0?1:0), cc+1, k->second);
		}
	}
}
void func() {
	for (int len = 1; len <= 10; ++ len) {
		hoge[len].clear();
	}
	for (int i = 0; i < N; ++ i) {
		hoge[D[i].length()].insert(i);
		fuga[i] = 0;
		for (int j = 0; j != D[i].length(); ++ j) {
			fuga[i] |= 1<<(D[i][j]-'a');
		}
	}
	for (int len = 1; len <= 10; ++ len) {
		for (char c = 'a'; c <= 'z'; ++ c) {
			map<set<int>, set<int> > a;
			for (set<int>::iterator i = hoge[len].begin();
				i != hoge[len].end(); ++ i)
			{
				set<int> b;
				for (int k = 0; k < len; ++ k) {
					if (D[*i][k] == c) b.insert(k);
				}
				a[b].insert(*i);
			}
			int d = 1;
			for (map<set<int>, set<int> >::iterator i = a.begin();
				i != a.end(); ++ i)
			{
				for (set<int>::iterator j = i->second.begin();
					j != i->second.end(); ++ j)
				{
					if (i->first.empty()) {
						piyo[c-'a'][*j] = 0;
					} else {
						piyo[c-'a'][*j] = d;
					}
				}
				if (!i->first.empty()) ++ d;
			}
		}
	}
	for (idx = 0; idx < M; ++ idx) {
		p = 0;
		m = -1;
		for (int len = 1; len <= 10; ++ len) {
			f(0, 0, hoge[len]);
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