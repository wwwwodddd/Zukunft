#include <bits/stdc++.h>
using namespace std;
map<int, vector<pair<int, char> > > g;
int n;
int x[200020];
int y[200020];
char d[200020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	scanf("%s", d);
	for (int i = 0; i < n; i++)
	{
		g[y[i]].push_back(make_pair(x[i], d[i]));
	}
	long long z = 0;
	for (auto&i: g)
	{
		sort(i.second.begin(), i.second.end());
		int c = 0;
		for (auto j: i.second)
		{
			if (j.second == 'R')
			{
				c++;
			}
			else
			{
				z += c;
			}
		}
	}
	cout << (z > 0 ? "Yes" : "No") << endl;
	return 0;
}
