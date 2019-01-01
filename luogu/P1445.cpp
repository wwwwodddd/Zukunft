#include <bits/stdc++.h>
using namespace std;
int v[1000020];
int n, p = 1000000007;
long long z = 1;
int F(int n, int p) {
	int re = 0;
	while (n > 0) {
		n /= p;
		re += n;
	}
	return re;
}
int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (v[i] == 0) {
			z = z * (2 * F(n, i) + 1) % p;
			for (int j = i; j <= n; j += i) {
				v[j] = i;
			}
		}
	}
	cout << z << endl;
}