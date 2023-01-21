#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t, n;
int a[5020];
int d[5020];
int f[5020][5020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		vector<int> b[2];
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			b[a[i] & 1].push_back(i);
		}
		for (int i = 0; i <= n; i++)
		{
			d[i] = -1;
			for (int j = 0; j < i; j++)
			{
				if (a[i] % 2 != a[j] % 2 && abs(a[i] - a[j]) > 1)
				{
					d[i] = j;
				}
			}
			for (int j = 0; j <= n; j++)
			{
				f[i][j] = 0;
			}
		}
		f[0][0] = 1;
		for (int i = 0; i <= b[0].size(); i++)
		{
			for (int j = 0; j <= b[1].size(); j++)
			{
				if (i < b[0].size() && (j == b[1].size() || d[b[0][i]] < b[1][j]))
				{
					f[i + 1][j] = (f[i + 1][j] + f[i][j]) % p;
				}
				if (j < b[1].size() && (i == b[0].size() || d[b[1][j]] < b[0][i]))
				{
					f[i][j + 1] = (f[i][j + 1] + f[i][j]) % p;
				}
			}
		}
		printf("%d\n", f[b[0].size()][b[1].size()]);
	}
	return 0;
}