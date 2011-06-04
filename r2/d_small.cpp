#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<int> > a, pr;
int f(int p, vector<int> x) {
	if (p != 1) {
		x[p] = 2;
		for (int i = 0; i < a[p].size(); ++ i) {
			if (x[a[p][i]] == 0) x[a[p][i]] = 1;
		}
	}
	if (p == 0) {
		int r = 0;
		for (int i = 0; i < x.size(); ++ i) {
			if (x[i] == 1) ++ r;
		}
		return r;
	} else {
		int r = 0;
		for (int i = 0; i < pr[p].size(); ++ i) {
			r = max(r, f(pr[p][i], x));
		}
		return r;
	}
}
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		int P, W;
		cin >> P >> W;
		a = vector<vector<int> >(P);
		for (int i = 0; i < W; ++ i) {
			string xy;
			cin >> xy;
			int x = atoi(xy.c_str());
			int y = atoi(xy.c_str()+1+xy.find(','));
			a[x].push_back(y);
			a[y].push_back(x);
		}
		pr = vector<vector<int> > (P);
		vector<int> D(P, -1);
		queue<int> Q;
		D[0] = 0;
		Q.push(0);
		while(!Q.empty()) {
			int p = Q.front();
			Q.pop();
			for (int i = 0; i < a[p].size(); ++ i) {
				int q = a[p][i];
				if (D[q] < 0) {
					pr[q].push_back(p);
					D[q] = D[p] + 1;
					if (q != 1) Q.push(q);
				} else if (D[q] == D[p]+1) {
					pr[q].push_back(p);
				}
			}
		}
		vector<int> x(P);
		int r = f(1, x);
		cout << "Case #"<<tt<<": " << D[1]-1 << " " << r << endl;
	}
}
