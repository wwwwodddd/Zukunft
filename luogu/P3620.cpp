#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100020];
int nxt[100020];
int pre[100020];
set<pair<int, int> > s;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		pre[i + 1] = i;
		nxt[i] = i + 1;
	}
	for (int i = n - 1; i > 0; i--) {
		a[i] -= a[i - 1];
		s.insert(make_pair(a[i], i));
	}
	a[0] = 1e9;
	a[n] = 1e9;
	int z = 0;
	for (int i = 0; i < k; i++) {
		int x = s.begin()->second;
		s.erase(s.begin());
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