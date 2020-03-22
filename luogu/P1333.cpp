#include <bits/stdc++.h>
using namespace std;
int n, ans;
map<string, int> g;
int d[500020];
int f[500020];
int get(string s) {
	if (g.find(s) == g.end()) {
		g[s] = n;
		f[n] = n;
		n++;
	}
	return g[s];
}
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main() {
	string a, b;
	while (cin >> a >> b) {
		int x = get(a);
		int y = get(b);
		d[x]++;
		d[y]++;
		f[F(x)] = F(y);
	}
	for (int i = 0; i < n; i++) {
		if (F(i) != F(0)) {
			printf("Impossible\n");
			return 0;
		}
		if (d[i] & 1) {
			ans++;
		}
	}
	if (ans > 2) {
		printf("Impossible\n");
		return 0;
	}
	printf("Possible\n");
	return 0;
}