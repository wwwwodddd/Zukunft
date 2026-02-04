#include <bits/stdc++.h>
using namespace std;
int t, n = 100000, m;
int s[100020];
int z[100020];
vector<int> d[100020];
int main()
{
	for (int i = 1; i <= n; i++)
	{
		z[i]++;
		for (int j = i; j <= n; j += i)
		{
			z[j] = max(z[j], z[i]);
		}
	}
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> s[i];
		}
		sort(s, s + m, greater<int>());
		int c = 0;
		for (int i = 1; i <= n; i++)
		{
			c = max(c, z[i]);
		}
		if (c > m)
		{
			printf("-1\n");
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				printf("%d%c", s[z[i] - 1], i == n ? '\n' : ' ');
			}
		}
	}
	return 0;
}