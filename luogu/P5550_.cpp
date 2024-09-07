#include <bits/stdc++.h>
using namespace std;
int n, s, m;
long long k;
void mul(long long a[81], long long b[81]) {
	long long w[81] = {};
	for (int i = 1; i <= n; i++) {
		w[i] = a[b[i]];
	}
	memcpy(a, w, sizeof w);
}
long long a[81];
long long b[81];
long long c[81];
int main() {
	cin >> n >> s >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		b[i] = i;
	}
	swap(b[s], b[m]);
	for (int i = 1; i < n; i++)
	{
		c[i] = i + 1;
	}
	c[n] = 1;
	mul(b, c);
	for (; k > 0; k >>= 1) {
		if (k & 1) {
			mul(a, b);
		}
		mul(b, b);
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
