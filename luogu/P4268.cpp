#include <bits/stdc++.h>
using namespace std;
long long ans;
vector<int> a[100020];
int b[100020];
int s[100020];
int n;
void dfs1(int x, int y)
{
	if (!a[x].size())
	{
		s[x] = 1;
		ans += y - 1;
	}
	for (int i: a[x])
	{
		dfs1(i, b[i] + 1 + y);
		s[x] += s[i];
	}
}
void dfs2(int x, long long y)
{
	ans = min(ans, y);
	for (int i: a[x])
	{
		if (a[i].size() > 0)
		{
			dfs2(i, y - s[i] * (b[i] + 1) + (s[1] - s[i]) * 3);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		int l, x;
		cin >> s;
		cin >> l;
		b[i] = s.size();
		for (int j = 0; j < l; j++)
		{
			cin >> x;
			a[i].push_back(x);
		}
	}
	dfs1(1, 0);
	dfs2(1, ans);
	printf("%lld\n", ans);
	return 0;
}