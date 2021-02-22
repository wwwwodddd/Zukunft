#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, q, ss;
int c[200020];
vector<pair<int, int> > p[200020];
int r[200020];
int s[200020];
ll t[200020];
ll z[200020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &c[i]);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		p[y].push_back(make_pair(x, i));
	}
	for (int i = 1; i <= m; i++)
	{
		if (i == 1)
		{
			r[ss] = i;
			s[ss] = 1;
			t[ss] = 0;
			ss++;
		}
		else
		{
			while (true)
			{
				ll b = i - r[ss - 1];
				ll pos = max((c[i] - c[r[ss - 1]] + b - 1) / (2 * b), 1LL);
				if (ss > 1 && pos <= s[ss - 1])
				{
					ss--;
				}
				else
				{
					r[ss] = i;
					s[ss] = pos;
					t[ss] = t[ss - 1] + (pos - s[ss - 1]) * c[r[ss - 1]] + (ll)pos * pos * (i - r[ss - 1]);
					ss++;
					break;
				}
			}
		}
		for (pair<int, int> j: p[i])
		{
			int bs = upper_bound(s, s + ss, j.first) - s - 1;
			z[j.second] = t[bs] + (ll)(j.first - s[bs]) * c[r[bs]] + (ll)j.first * j.first * (i - r[bs]);
		}
	}
	for (int i = 0; i < q; i++)
	{
		printf("%lld\n", z[i]);
	}
	return 0;
}