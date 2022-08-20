#include <bits/stdc++.h>
using namespace std;
int n, k, m, x, y;
int z[200020];
int p[200020];
vector<int> a[200020];
set<int> s;
int main()
{
	memset(z, -1, sizeof z);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		auto it = s.upper_bound(x);
		if (it == s.end())
		{
			y = m++;
		}
		else
		{
			y = p[*it];
			s.erase(it);
		}
		p[x] = y;
		a[y].push_back(x);
		if (a[y].size() == k)
		{
			for (int j : a[y])
			{
				z[j] = i;
			}
		}
		else
		{
			s.insert(x);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << z[i] << endl;
	}
	return 0;
}
