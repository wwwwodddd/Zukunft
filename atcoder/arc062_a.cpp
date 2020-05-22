#include <bits/stdc++.h>
using namespace std;
long long n, a = 1, b = 1, c, d, t;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> c >> d;
		t = max((a + c - 1) / c, (b + d - 1) / d);
		a = c * t;
		b = d * t;
	}
	cout << (a + b) << endl;
	return 0;
}