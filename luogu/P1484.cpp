#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a[500020];
int nxt[500020];
int pre[500020];
set<pair<long long, int> > s;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		s.insert(make_pair(a[i], i));
		pre[i] = i - 1;
		nxt[i] = i + 1;
	}
	nxt[0] = 1;
	pre[n + 1] = n;
	a[0] = -1e18;
	a[n + 1] = -1e18;
	long long z = 0;
	for (int i = 0; i < k; i++) {
		int x = s.rbegin()->second;
		s.erase(--s.end());
		if (a[x] < 0) {
			break;
		}
		z += a[x];
		s.erase(make_pair(a[pre[x]], pre[x]));
		s.erase(make_pair(a[nxt[x]], nxt[x]));
		a[x] = a[pre[x]] + a[nxt[x]] - a[x];
		s.insert(make_pair(a[x], x));
		pre[x] = pre[pre[x]];
		nxt[x] = nxt[nxt[x]];
		nxt[pre[x]] = x;
		pre[nxt[x]] = x;
	}
	printf("%lld\n", z);
	return 0;
}