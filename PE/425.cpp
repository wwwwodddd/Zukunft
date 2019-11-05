#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[10000020];
int v[10000020];
int n = 10000000;
long long ans;
int a[20], c;

int F(int x) {
	return f[x] != x ? f[x] = F(f[x]) : x;
}

void U(int x, int y) {
	x = F(x);
	y = F(y);
	f[x] = y;
}

int to_i() {
	int re = 0;
	for (int i = c - 1; i >= 0; i--) {
		re = re * 10 + a[i];
	}
	return re;
}
void work(int x) {
	memset(a, 0, sizeof a);
	c = 0;
	int t = x;
	while (t > 0) {
		a[c++] = t % 10;
		t /= 10;
	}
	for (int i = 0; i < c; i++) {
		int u = a[i];
		for (int j = (i == c - 1); j < u; j++) {
			a[i] = j;
			int y = to_i();
			if (v[y] == y) {
				U(x, y);
			}
		}
		a[i] = u;
	}
	if (a[c - 2] != 0) {
		a[c - 1] = 0;
		int y = to_i();
		if (v[y] == y) {
			U(x, y);
		}
	}
}
int main() {
	v[0] = -1;
	v[1] = -1;
	for (int i = 2; i <= n; i++) {
		if (v[i] > 0) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			v[j] = i;
		}
	}

	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (v[i] != i) {
			continue;
		}
		work(i);
		if (F(i) != F(2)) {
			ans += i;
		}
	}
	printf("%lld\n", ans);
	return 0;
}