#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > > e;
int f[520];
int x[520];
int y[520];
int n, m;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d%d", &m, &n);
	m = n - m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		for (int j = 0; j < i; j++)
		{
			e.push_back(make_pair((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]), make_pair(i, j)));
		}
		f[i] = i;
	}
	sort(e.begin(), e.end());
	for (unsigned i = 0; i < e.size(); i++)
	{
		int x = e[i].second.first;
		int y = e[i].second.second;
		if (F(x) != F(y))
		{
			if (!--m)
			{
				printf("%.2f\n", sqrt(e[i].first));
				break;
			}
			f[F(x)] = F(y);
		}
	}
	return 0;
}