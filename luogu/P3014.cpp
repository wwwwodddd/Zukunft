#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[21];
long long fac[21];
void decode(long long x) {
	int v[21] = {};
	for (int i = 0; i < n; i++) {
		int cnt = x % fac[n - i] / fac[n - 1 - i];
		for (int j = 0; j < n; j++) {
			if (v[j] == 0) {
				if (cnt == 0) {
					a[i] = j;
					v[j] = 1;
					break;
				} else {
					cnt--;
				}
			}
		}
	}
}
long long encode() {
	int v[21] = {};
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
	scanf("%d%d", &n, &m);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
	}
	for (int i = 0; i < m; i++) {
		char o;
		scanf(" %c", &o);
		if (o == 'P') {
			long long x;
			scanf("%lld", &x);
			decode(x - 1);
			for (int i = 0; i < n; i++) {
				printf("%d%c", a[i] + 1, i == n - 1 ? '\n' : ' ');
			}
		} else {
			for (int i = 0; i < n; i++) {
				scanf("%d", &a[i]);
				a[i]--;
			}
			printf("%lld\n", encode() + 1);
			
		}
	}
}