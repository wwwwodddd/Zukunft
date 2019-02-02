#include <bits/stdc++.h>
using namespace std;
int p = 1000000007;
int M = 1e9;
int n, m, ans;
int c[200020];
vector<pair<int, int> > b;
long long f[200020];
int F(int n, int m, int r) {
	if (n == -1) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}
	for (int i = 0; i < n + 2; i++) {
		f[i] = 0;
	}
	f[0] = 1;
	long long u = f[0];
	long long v = 1;
	for (int i = 0; i < m; i++) {
		v = v * r % p;
	}
	for (int i = 1; i < n + 2; i++) {
		f[i] = u;
		u = (u * r + f[i]) % p;
		if (i - m >= 0) {
			u = (u - f[i - m] * v) % p;
		}
		if (u < 0) {
			u += p;
		}
	}
	return f[n + 1];
}

int main() {
//  scanf("%d%d%d", &n, &m, &M);
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n - m; i++) {
		scanf("%d", &c[i]);
	}
	b.push_back(make_pair(0, 1));
	for (int i = 0, j; i <= n - m; i = j) {
		j = i;
		while (j <= n - m && c[j] == c[i]) {
			j++;
		}
		b.push_back(make_pair(c[i], j - i));
	}
	b.push_back(make_pair(0, 1));
	ans = 1;
	for (int i = 1; i < b.size() - 1; i++) {
		if (b[i - 1].first < b[i].first && b[i].first > b[i + 1].first) {
			ans = (long long)ans * F(b[i].second + m - 1, m, M - b[i].first) % p;
		} else if (b[i - 1].first > b[i].first && b[i].first < b[i + 1].first) {
			ans = (long long)ans * F(b[i].second - m - 1, m, M - b[i].first) % p;
		} else {
			ans = (long long)ans * F(b[i].second - 1, m, M - b[i].first) % p;
		}
	}
	cout << ans << endl;
	return 0;
}