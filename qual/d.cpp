#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> order;
double func() {
	int cnt = 0;
	for (int i = 0; i < N; ++ i) {
		if (order[i] != i+1) ++ cnt;
	}
	return cnt;
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++ t) {
		cin >> N;
		order = vector<int>(N);
		for (int i = 0; i < N; ++ i) cin >> order[i];
		printf("Case #%d: %f\n", t, func());
	}
}