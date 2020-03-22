#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		double x;
		int y;
		cin >> x >> y;
		for (int j = 1; j <= y; j++) {
			ans ^= (int)(j * x);
		}
	}
	cout << ans << endl;
}