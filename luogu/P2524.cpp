#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10];
long long fac[10];
long long encode() {
	int v[10] = {};
	long long re = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < a[i]; j++) {
			if (v[j] == 0) {
				cnt++;
			}
		}
		v[a[i]] = 1;
		re += cnt * fac[n - 1 - i];
	}
	return re;
}
int main() {
	scanf("%d", &n);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%1d", &a[i]);
		a[i]--;
	}
	printf("%lld\n", encode() + 1);
}