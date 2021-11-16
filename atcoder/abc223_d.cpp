#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[200020];
int d[200020];
set<int> s;
vector<int> z;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		a[x].push_back(y);
		d[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)
		{
			s.insert(i);
		}
	}
	while (s.size() > 0)
	{
		int x = *s.begin();
		z.push_back(x);
		s.erase(s.begin());
		for (int i: a[x])
		{
			if (--d[i] == 0)
			{
				s.insert(i);
			}
		}
	}
	if (z.size() == n)
	{
		for (int i: z)
		{
			cout << i << " ";
		}
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}
