#include <bits/stdc++.h>
using namespace std;


vector<int> a[25000002];

long long ans = 0;
int main() {
	int n = 25000000;
	for (int i = 1; i <= n + 1; i++) {
		for (int j = i; j <= n + 1; j += i) {
			a[j].push_back(i);
		}
	}
	printf("prepare\n");
	ans += 1; // 1 1 1
	for (int i = 2; i <= n; i++) {
		if (i % 100000 == 0) {
			printf("%d\n", i);
		}
		long long b = i;
		set<long long> s;
		for (int j = 0; j < a[i - 1].size(); j++) {
			for (int k = 0; k < a[i + 1].size(); k++) {
				s.insert((long long)a[i - 1][j] * a[i + 1][k]);
			}
		}
		for (long long x: s) {
			long long y = (b - 1) * (b + 1) / x;
			if (x > y) {
				break;
			}
			if ((x + y) % 2 == 0) {
				long long c = (x + y) / 2;
				long long a = (y - x) / 2;
				if (a <= b && b <= c && a + b + c <= n) {
//					printf("%lld %lld %lld\n", a, b, c);
					ans += 1;
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}