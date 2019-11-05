#include <bits/stdc++.h>
using namespace std;
set<long long> z;
int v[1000020];
int main() {
	long long n = 1e12;
	int N = 1e6;
	for (int i = 2; i <= N; i++) {
		if (v[i] > 0) {
			continue;
		}
		for (int j = i; j <= N; j += i) {
			v[j] = i;
		}
	}
	for (int i = 2; (long long)i * i * i * i <= n; i++) {
		long long s = 1;
		for (int j = 0; s <= n; j++) {
			if (j >= 2 && v[j] != j) {
				z.insert(s);
			}
			s *= i;
		}
	}
	for (int i = 2; i <= N; i++) {
		if (v[i] == i) {
			continue;
		}
		for (long long j = (long long)i * i; j <= n; j *= i) {
			z.insert(j);
		}
	}
	long long ans = 0;
	z.erase(16);

	for (long long i: z) {
		ans += i;
//		cout << i << endl;
	}
	cout << ans << endl;

	return 0;
}