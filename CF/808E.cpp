#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[4];
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return (long long)a.second * b.first > (long long)b.second * a.first;
}

long long f[1000020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= 3; i++)
	{
		sort(a[i].begin(), a[i].end());
	}
	long long ans = 0;
	while (m > 60)
	{
		long long w = 1;
		long long c = -1;
		for (int i = 1; i <= 3; i++)
		{
			if (a[i].size() > 4)
			{
				if (a[i][a[i].size() - 1] * w > c * i)
				{
					c = a[i][a[i].size() - 1];
					w = i;
				}
			}
		}
		if (c == -1)
		{
			break;
		}
		m -= w;
		ans += c;
		a[w].pop_back();
	}
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 0; j < a[i].size(); j++)
		{
			for (int k = m; k >= i; k--)
			{
				f[k] = max(f[k], f[k - i] + a[i][j]);
			}
		}
	}
	cout << (ans + f[m]) << endl;
	return 0;
}