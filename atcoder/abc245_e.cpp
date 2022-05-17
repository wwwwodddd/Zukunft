#include <bits/stdc++.h>
using namespace std;
int n, m, z;
pair<int, int> a[400020];
multiset<int> s;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].second;
		a[i].second = -a[i].second;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a[i + n].first;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a[i + n].second;
	}
	sort(a, a + n + m);
	for (int i = n + m - 1; i >= 0; i--)
	{
		if (a[i].second > 0)
		{
			s.insert(a[i].second);
		}
		else
		{
			auto it = s.lower_bound(-a[i].second);
			if (it != s.end())
			{
				s.erase(it);
				z++;
			}
		}
	}
	cout << (z == n ? "Yes" : "No") << endl;
	return 0;
}
