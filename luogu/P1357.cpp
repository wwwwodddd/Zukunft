#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
long long n;
int m, l, sz, z;
int a[32][32];
int b[32][32];
void mul(int a[32][32], int b[32][32]) {
	int w[32][32] = {};
	for (int i = 0; i < sz; i++) {
		for (int k = 0; k < sz; k++) {
			if (a[i][k] == 0) {
				continue;
			}
			for (int j = 0; j < sz; j++) {
				w[i][j] = (w[i][j] + (long long)a[i][k] * b[k][j]) % p;
			}
		}
	}
	memcpy(a, w, sizeof w);
}
int main() {
	cin >> n >> m >> l;
	sz = 1 << m;
	for (int i = 0; i < sz; i++)
	{
		if (__builtin_popcount(i) <= l)
		{
			a[i][i] = 1;
			int j = i >> 1;
			if (__builtin_popcount(j) <= l)
			{
				b[i][j] = 1;
			}
			j |= 1 << m - 1;
			if (__builtin_popcount(j) <= l)
			{
				b[i][j] = 1;
			}
		}
	}
	for (; n > 0; n >>= 1) {
		if (n & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	for (int i = 0; i < sz; i++)
	{
		z = (z + a[i][i]) % p;
	}
	cout << z << endl;
	return 0;
}