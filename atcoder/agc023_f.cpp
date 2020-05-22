#include <bits/stdc++.h>
using namespace std;
struct N {
	long long c0, c1, id;
};
bool operator<(const N &a, const N &b) {
	return a.c1 * b.c0 < a.c0 * b.c1 || a.c1 * b.c0 == a.c0 * b.c1 && a.id < b.id;
}
set<N> s;
int n;
int f[200020];
int p[200020];
int c0[200020];
int c1[200020];
long long z;
int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c1[i]);
		c0[i] = 1 - c1[i];
		f[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		s.insert({c0[i], c1[i], i});
	}
	while (s.size()) {
		N u = *s.begin();
		s.erase(s.begin());
		int x = u.id;
		int y = f[x] = F(p[x]);
		z += (long long)c1[y] * c0[x];
		if (y != 1) {
			s.erase({c0[y], c1[y], y});
		}
		c0[y] += c0[x];
		c1[y] += c1[x];
		if (y != 1) {
			s.insert({c0[y], c1[y], y});
		}
	}
	printf("%lld\n", z);
	return 0;
}