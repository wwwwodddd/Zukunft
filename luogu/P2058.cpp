#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int> > q;
int n, t, k, x, cnt;
int v[100020];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &t, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &x);
			if (v[x] == 0) {
				cnt++;
			}
			v[x]++;
			q.push(make_pair(t, x));
		}
		while (q.size() && q.front().first <= t - 86400) {
			int y = q.front().second;
			v[y]--;
			if (v[y] == 0) {
				cnt--;
			}
			q.pop();
		}
		printf("%d\n", cnt);
	}
	return 0;
}