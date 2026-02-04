#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[20];
set<long long> s;
void dfs(int d, int x, int y, int z)
{
	if (d == n)
	{
		long long a[3] = {x, y, z};
		sort(a, a + 3);
		if (a[0] + a[1] > a[2])
		{
			s.insert(a[0] * 100000000 + a[1] * 10000 + a[2]);
		}
		return;
	}
	dfs(d + 1, x + a[d], y, z);
	dfs(d + 1, x, y + a[d], z);
	dfs(d + 1, x, y, z + a[d]);
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		dfs(0, 0, 0, 0);
		cout << s.size() << endl;
		s.clear();
	}
	return 0;
}