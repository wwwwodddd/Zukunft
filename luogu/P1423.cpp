#include <bits/stdc++.h>
using namespace std;
double s, t = 2;
int n;
int main() {
	cin >> s;
	while (s > 0) {
		s -= t;
		t *= 0.98;
		n++;
	}
	cout << n << endl;
	return 0;
}
