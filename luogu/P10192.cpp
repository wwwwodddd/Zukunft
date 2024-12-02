#include <bits/stdc++.h>
using namespace std;
int a[300020][2];
int s[300020];
int d[300020];
int t, n, m, k, x;
vector<string> z;
void gao()
{
	z.clear();
	for (int i = 0; i < m; i++)
	{
		if (n + a[i][0] + s[i + 1] > 0 && n + a[i][0] > 0 && n + a[i][0] + d[i + 1] > 0)
		{
			n += a[i][0];
			z.push_back("Even");
		}
		else
		{
			n += a[i][1];
			z.push_back("Odd");
		}
		if (n <= 0)
		{
			cout << -1 << endl;
			return;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cout << z[i] << (i == m - 1 ? "\n" : " ");
	}
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m >> k;
		memset(a, 0x3f, sizeof a);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < k; j++)
			{
				cin >> x;
				a[i][x % 2] = min(a[i][x % 2], x);
				a[i][1 - x % 2] = min(a[i][1 - x % 2], -x);
			}
		}
		memset(s, 0, sizeof s);
		memset(d, 0, sizeof d);
		for (int i = m - 1; i >= 0; i--)
		{
			s[i] = s[i + 1] + max(a[i][0], a[i][1]);
			d[i] = min(d[i + 1] + max(a[i][0], a[i][1]), 0);
		}
		gao();
	}
	return 0;
}