#include <bits/stdc++.h>
using namespace std;
long long b[10010001];
long long f[20010001];
long long v[20010001];
long long a[10000];
int p = 1000000007;

long long C(int n, int m) {
	return f[n] * v[m] % p * v[n - m] % p;
}
int G(int n) {
	for (int i = 0; i <= n; i++) {
		b[i] = 1;
	}
	for (int j = (int)sqrt(n); j >= 1; j--) {
		for (int i = (int)ceil(j * sqrt(n)); i <= n; i++) {
			b[i] += b[i - 1];
			b[i] %= p;
		}
	}
	return b[n];
}

int F(int n) {
	long long ans = 1;
	a[(int)sqrt(n)] = n + 1;
	for (int j = (int)sqrt(n); j >= 1; j--) {
		ans += C(n - (int)ceil(j * sqrt(n)) + 1 + j - 1, j - 1);
		a[j - 1] = (int)ceil(j * sqrt(n));
		ans += C(n - a[j - 1] + j, j);
		ans -= C(n - a[j] + 1 + j, j);
		ans %= p;
		if (ans < 0) {
			ans += p;
		}
	}
	return ans;

}
bool P(int n) {
	if (n < 2) {
		return false;
	}
	for (int i = 2; i <= n / i; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	v[0] = 1;
	v[1] = 1;
	for (int i = 2; i < 20010001; i++) {
		v[i] = v[p % i] * (p - p / i) % p;
	}
	f[0] = 1;
	for (int i = 1; i < 20010001; i++) {
		f[i] = f[i - 1] * i % p;
		v[i] = v[i - 1] * v[i] % p;
	}
//	cout << G(90) << endl;
//	cout << F(90) << endl;
//	return 0;
	long long ans = 0;
	for (int i = 10000000; i <= 10010000; i++) {
		if (P(i)) {
			fprintf(stderr, "%d\n", i);
			ans += F(i);
			ans %= p;
		}
	}
	cout << ans << endl;
	return 0;
}