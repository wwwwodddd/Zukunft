#include <bits/stdc++.h>
using namespace std;
int n, x, y, z, M, flag;
vector<int> a[100020];

int dfs(int x, int y) {
	multiset<int> b;
	for (int i = 0; i < a[x].size(); i++) {
		if (a[x][i] != y) {
			int l = dfs(a[x][i], x);
			b.insert(l + 1);
			if (!flag)
			{
				return 0;
			}
		}
	}
	int only = 0;
	while (b.size() > 1)
	{
		int u = *b.begin();
		b.erase(b.begin());
		if (u < M)
		{
			multiset<int>::iterator it = b.lower_bound(M - u);
			if (it == b.end())
			{
				if (only == 0)
				{
					only = u;
					continue;
				}
				flag = false;
				return 0;
			}
			if (b.size() == 1 && *it >= M)
			{
				return *b.begin();
			}
			b.erase(it);
		}
	}
	if (b.size() == 0)
	{
		return only;
	}
	else
	{
		if (only > 0)
		{
			flag = false;
			return 0;
		}
		return *b.begin();
	}
}
bool ok() {
	flag = true;
	int res = dfs(1, 0);
	return flag && (res >= M || res == 0);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int L = 1, R = n;
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