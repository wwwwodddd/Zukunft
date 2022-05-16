#include <bits/stdc++.h>
using namespace std;
int read()
{
	int n=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
		;
	for(;isdigit(c);c=getchar())
		n=n*10+c-'0';
	return n;
}
vector<pair<int, long long> > s[1020];
int main()
{
	int t = read();
	for (int tt = 1; tt <= t; tt++)
	{
		int n = read();
		int m = read();
		for (int i = 1; i <= 1000; i++)
		{
			s[i].clear();
			s[i].push_back(make_pair(0, 0));
		}
		for (int i = 1; i <= n; i++)
		{
			int x = read();
			for (int j = 1; j * j <= x && j <= 1000; j++)
			{
				if (x % j == 0)
				{
					s[j].push_back(make_pair(i, s[j].back().second + x));
					int k = x / j;
					if (j < k && k <= 1000)
					{
						s[k].push_back(make_pair(i, s[k].back().second + x));
					}
				}
			}
		}
		printf("Case #%d\n", tt);
		for (int i = 0; i < m; i++)
		{
			int v = read();
			int x = upper_bound(s[v].begin(), s[v].end(), make_pair(read(), -1LL)) - s[v].begin() - 1;
			int y = upper_bound(s[v].begin(), s[v].end(), make_pair(read() + 1, -1LL)) - s[v].begin() - 1;
			printf("%lld\n", s[v][y].second - s[v][x].second);
		}
		printf("\n");
	}
	return 0;
}