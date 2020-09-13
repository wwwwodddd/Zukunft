#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, M, cnt;
vector<pair<int, int> > a[50020];
int dfs(int x, int y) {
	vector<int> b;
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i].first != y) {
			int l = dfs(a[x][i].first, x) + a[x][i].second;
			if (l >= M) {
				cnt++;
			} else {
				b.push_back(l);
			}
		}
	}
	b.push_back(0);
	sort(b.begin(), b.end(), greater<int>());
	int res = 0, ret = -1;
	int L = 0, R = b.size() - 1;
	while (L < R) {
		if (b[L] + b[R] >= M) {
			L++;
			R--;
			res++;
		} else {
			R--;
		}
	}
	cnt += res;
	L = res;
	R = res + 1;
	int tmp = 0;
	while (R <= 2 * res) {
		if (b[L] + b[R] >= M) {
			L--;
			R++;
		} else {
			if (tmp == 0) {
				tmp++;
				ret = b[L];
				L--;
			} else if (tmp == 1) {
				tmp++;
				break;
			}
		}
	}
	if (tmp == 0) {
		return b[0];
	} else if (tmp == 1) {
		return ret;
	}
	L = 0;
	R = 2 * res;
	while (L < R) {
		if (b[L] + b[R] >= M) {
			L++;
			R--;
		} else {
			return b[R];
		}
	}
	return b[R];
}
bool ok() {
	cnt = 0;
	dfs(1, 0);
	return cnt >= m;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	int L = 0, R = 1e9;
	while (L < R - 1) {
		M = (L + R) / 2;
		if (ok()) {
			L = M;
		} else {
			R = M;
		}
	}
	printf("%d\n", L);
	return 0;
}