#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[200020];
vector<int> z;
int in[200020];
int out[200020];
void dfs(int x)
{
	while (a[x].size() > 0)
	{
		int y = a[x].back();
		a[x].pop_back();
		dfs(y);
	}
	z.push_back(x);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		in[y]++;
		out[x]++;
	}
	dfs(1);
	if (out[1] != in[1] + 1 || in[n] != out[n] + 1)
	{
		z.clear();
	}
	for (int i = 2; i < n; i++)
	{
		if (in[i] != out[i])
		{
			z.clear();
		}
	}
	if (z.size() == m + 1 && z[0] == n)
	{
		reverse(z.begin(), z.end());
		for (auto i : z)
		{
			cout << i << " ";
		}
	}
	else
	{
		cout << "IMPOSSIBLE";
	}
	return 0;
}