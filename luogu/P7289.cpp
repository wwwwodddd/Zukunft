#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[100020];
int p[100020];
int v[100020];
int c[100020], cnt;
int z[100020];
int n;
long long m, l;
int main()
{
	scanf("%d%lld%lld", &n, &l, &m);
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
		a[i].push_back(make_pair(i, 0));
	}
	for (int i = 1; i <= l; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		swap(p[x], p[y]);
		a[p[x]].push_back(make_pair(x, i));
		a[p[y]].push_back(make_pair(y, i));
	}
	for (int i = 1; i <= n; i++)
	{
		if (!v[i])
		{
			vector<int> d;
			while (!v[i])
			{
				d.push_back(i);
				v[i] = 1;
				i = p[i];
			}
			reverse(d.begin(), d.end());
			vector<pair<int, long long> > f;
			long long t = 0;
			for (int j: d)
			{
				for (pair<int, int> k: a[j])
				{
					f.push_back(make_pair(k.first, k.second + t));
				}
				t += l;
			}
			for (int j: d)
			{
				for (pair<int, int> k: a[j])
				{
					f.push_back(make_pair(k.first, k.second + t));
				}
				t += l;
			}
			int j = 0, k = 0;
			for (int i = 0; i < d.size(); i++)
			{
				while (k < f.size() && f[k].second <= i * l + m)
				{
					cnt += !c[f[k++].first]++;
				}
				while (j < f.size() && f[j].second < i * l)
				{
					cnt -= !--c[f[j++].first];
				}
				z[d[i]] = cnt;
			}
			while (j < k)
			{
				cnt -= !--c[f[j++].first];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}