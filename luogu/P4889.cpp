#include <bits/stdc++.h>
using namespace std;
map<int, int> g;
int n, m, x;
long long ans;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		ans += g[i + x]++;
		ans += g[i - x]++;
	}
	cout << ans << endl;
	return 0;
}