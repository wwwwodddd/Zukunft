#include <bits/stdc++.h>
using namespace std;
char s[1000020];
int p[1000020], n;
long long ans;
int main() {
	scanf("%d%s", &n, s + 1);
	int u = 0;
	for (int i = 2; i <= n; i++) {
		while (u > 0 && s[u + 1] != s[i]) {
			u = p[u];
		}
		if (s[u + 1] == s[i]) {
			u++;
		}
		p[i] = u;
	}
	for (int i = 1; i <= n; i++) {
		if (p[p[i]] > 0) {
			p[i] = p[p[i]];
		}
		if (p[i] > 0) {
			ans += i - p[i];
		}
	}
	cout << ans << endl;
}