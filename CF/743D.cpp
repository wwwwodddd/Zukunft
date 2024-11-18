#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long ans = -1e18;
int w[200020];
vector<int> a[200020];
pair<long long, long long> dfs(int x, int y)
{
	vector<long long> r;
	long long s = w[x];
	for (int i : a[x])
	{
		if (i != y)
		{
			pair<long long, long long> u = dfs(i, x);
			s += u.first;
			r.push_back(u.second);
		}
	}
	sort(r.begin(), r.end(), greater<long long>());
	if (r.size() >= 2)
	{
		ans = max(ans, r[0] + r[1]);
	}
	if (r.size() > 0)
	{
		return make_pair(s, max(s, r[0]));
	}
	else
	{
		return make_pair(s, s);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	if (ans == -1e18)
	{
		puts("Impossible");
	}
	else
	{
		printf("%lld\n", ans);
	}
	return 0;
}