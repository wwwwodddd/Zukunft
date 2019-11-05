#include <bits/stdc++.h>
using namespace std;
int v[60000020];
int d[60000020];
int c[60000020];
long long dd;
long long p = 1e18;
long long A[30000];
long long B[30000];

long long RA(int x, long long y) {
	if (x == 0) {
		cout << x << ' ' << y << endl;
	}
	for (; x <= 30000; x += x & -x) {
		A[x] += y;
		if (A[x] >= p) {
			A[x] -= p;
		}
	}
}

long long RB(int x, long long y) {
	for (; x <= 30000; x += x & -x) {
		B[x] += y;
		if (B[x] >= p) {
			B[x] -= p;
		}
	}
}

long long GA(int x) {
	long long re = 0;
	for (; x > 0; x -= x & -x) {
		re += A[x];
		if (re >= p) {
			re -= p;
		}
	}
	return re;
}


long long GB(int x) {
	long long re = 0;
	for (; x > 0; x -= x & -x) {
		re += B[x];
		if (re >= p) {
			re -= p;
		}
	}
	return re;
}

void inc (int x) {
	while (x > 1) {
		dd /= c[v[x]] + 1;
		c[v[x]]++;
		dd *= c[v[x]] + 1;
		x /= v[x];
	}
}

void dec (int x) {
	while (x > 1) {
		dd /= c[v[x]] + 1;
		c[v[x]]--;
		dd *= c[v[x]] + 1;
		x /= v[x];
	}
}

int main() {
	int n = 60000000;
	for (int i = 2; i <= n + 1; i++) {
		if (v[i] > 0) {
			continue;
		}
		for (int j = i; j <= n + 1; j += i) {
			v[j] = i;
		}
	}
	dd = 1;
	int maximum = 0;
	for (int i = 1; i <= n; i++) {
		inc(i + 1);
		if (i >= 2) {
			dec(i - 1);
		} else {
			dec(2);
		}
		d[i] = dd;
		maximum = max(maximum, d[i]);
	}
	cout << maximum << endl;
	long long ans = 0;
	for (int i = n; i > 0; i--) {
		RA(d[i], 1);
		RB(d[i], GA(d[i] - 1));
		ans += GB(d[i] - 1);
		if (ans >= p) {
			ans -= p;
		}
//		printf("%d %d %lld %lld\n", i, GA(d[i] - 1), d[i], GB(d[i] - 1));
	}
	cout << ans << endl;
	return 0;
}