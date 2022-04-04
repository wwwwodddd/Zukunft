#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[100020];
vector<pair<long long, pair<int, int> > > e;
int l[11];
long long dis(int i, int j)
{
	return (long long)(a[i].first - a[j].first) * (a[i].first - a[j].first) + (long long)(a[i].second - a[j].second) * (a[i].second - a[j].second);
}
int f[100020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
		f[i] = i;
	}
	sort(a, a + n);
	memset(l, -1, sizeof l);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (l[j] != -1) // (l[j])
			{
				e.push_back(make_pair(dis(l[j], i), make_pair(l[j], i)));
			}
		}
		l[a[i].second] = i;
	}
	sort(e.begin(), e.end());
	long long z = 0;
	for (int i = 0; i < e.size(); i++)
	{
		int x = F(e[i].second.first);
		int y = F(e[i].second.second);
		if (x != y)
		{
			z += e[i].first;
			f[x] = y;
		}
	}
	cout << z << endl;
	return 0;
}