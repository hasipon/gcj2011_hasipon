#include <iostream>
using namespace std;

long long N;
int PD, PG;
bool f() {
	if (PD == 0) {
		return PG != 100;
	} else if (PG == 100) {
		return PD == 100;
	} else {
		int a = 100;
		int pd = PD;
		for (int i = 2; i <= 100; ++ i) {
			while (pd % i == 0 && a % i == 0) {
				pd /= i;
				a /= i;
			}
		}
		return a <= N && PG != 0;
	}
}
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++ t) {
		cin >> N >> PD >> PG;
		cout << "Case #"<<t<<": " << (f()?"Possible":"Broken") << endl;
	}
}