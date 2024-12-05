#include <bits/stdc++.h>
using namespace std;
int k, m, n;
int p[200020];
int t[200020];
int f[200020];
vector<pair<int, int>> a[200020];
vector<long long> b;
int main()
{
	scanf("%d%d%d", &k, &m, &n);
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d", &p[i], &t[i]);
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &f[i]);
	}
	sort(f, f + m);
	b.resize(2);
	for (int i = 0; i < k; i++)
	{
		if (p[i] < f[0])
		{
			b[0] += t[i];
		}
		else if (p[i] > f[m - 1])
		{
			b[1] += t[i];
		}
		else
		{
			int j = lower_bound(f, f + m, p[i]) - f;
			a[j].push_back(make_pair(p[i], t[i]));
		}
	}
	for (int j = 1; j < m; j++)
	{
		sort(a[j].begin(), a[j].end());
		int l = (f[j] - f[j - 1] + 1) / 2;
		long long r = 0;
		long long s = 0;
		long long t = 0;
		for (int i = 0, i2 = 0; i < a[j].size(); i++)
		{
			s += a[j][i].second;
			t += a[j][i].second;
			while (a[j][i].first - a[j][i2].first >= l)
			{
				s -= a[j][i2++].second;
			}
			r = max(r, s);
		}
		b.push_back(r);
		b.push_back(t - r);
	}
	sort(b.begin(), b.end(), greater<long long>());
	long long z = 0;
	for (int i = 0; i < n && i < b.size(); i++)
	{
		z += b[i];
	}
	printf("%lld\n", z);
	return 0;
}