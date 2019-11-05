#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <queue>
using namespace std;
long long d[10020];
long long calc(int x) {
	if (x <= 2) {
		return 1;
	}
	memset(d, -1, sizeof d);
	d[1] = 1;
	d[2] = 2;
	queue<int>q;
	q.push(1);
	q.push(2);
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			long long v = (u * 10 + i) % x;
			if (d[v] == -1) {
				d[v] = d[u] * 10 + i;
				if (v == 0) {
					return d[v] / x;
				}
				q.push(v);
			}
		}
	}
	assert(false);
	return -1;
}
int main() {
	long long ans = 0;
	for (int i = 1; i <= 10000; i++) {
		if (i == 9999) {
			ans += 1111333355557778LL;
			continue;
		}
		long long t = calc(i);
		ans += t;
	}
	printf("%lld\n", ans);
	return 0;
}