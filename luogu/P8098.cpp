#include <bits/stdc++.h>
using namespace std;
vector<int> a[200020];
pair<int, int> b[200020];
long long z[100020];
int f[100020];
int n, c;
int k = 1e9;
void dfs(int x, long long d)
{
	z[x] = d + c++;
	for (int i: a[x])
	{
		dfs(i, d + k);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i].first);
		b[i].second = i;
		b[i + n] = make_pair(i, 0);
	}
	sort(b + 1, b + 1 + n + n);
	a[0].push_back(1);
	for (int i = 2; i <= 2 * n; i++)
	{
		if (b[i].second == 0)
		{
			if (b[i - 1].second == 0)
			{
				a[f[b[i - 1].first]].push_back(b[i].first);
				f[b[i].first] = f[b[i - 1].first];
			}
			else
			{
				a[b[i - 1].second].push_back(b[i].first);
				f[b[i].first] = b[i - 1].second;
			}
		}
	}
	dfs(0, -k);
	printf("%d\n", k);
	for (int i = 1; i <= n; i++)
	{
		printf("%lld\n", z[i]);
	}
	return 0;
}
