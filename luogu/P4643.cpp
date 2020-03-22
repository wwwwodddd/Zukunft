#include <bits/stdc++.h>
using namespace std;
int n, m;
int w[10020], x, y, z, ans;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		w[i] *= 2;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		w[x] += z;
		w[y] += z;
	}
	sort(w + 1, w + 1 + n);
	for (int i = n; i > 0; i -= 2) {
		ans += w[i] - w[i - 1];
	}
	cout << ans / 2 << endl;
	return 0;
}