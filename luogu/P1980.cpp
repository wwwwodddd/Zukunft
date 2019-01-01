#include <bits/stdc++.h>
using namespace std;
int n, x, d[10];
int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		int y = i;
		while (y > 0) {
			d[y % 10]++;
			y /= 10;
		}
	}
	cout << d[x] << endl;
	return 0;
}
