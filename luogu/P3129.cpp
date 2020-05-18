#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[50020];
int v[100020];
int f[50020];
int g[50020];
set<int> s, t;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		v[a[i]] = 1;
	}
	for (int i = 1; i <= 2 * n; i++)
	{
		if (!v[i])
		{
			s.insert(i);
			t.insert(-i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		set<int>::iterator it = s.lower_bound(a[i]);
		f[i] = f[i-1];
		if (it != s.end())
		{
			s.erase(it);
			f[i]++;
		}
	}
	for (int i = n; i >= 1; i--)
	{
		set<int>::iterator it = t.lower_bound(-a[i]);
		g[i] = g[i+1];
		if (it != t.end())
		{
			t.erase(it);
			g[i]++;
		}
	}
	for (int i = 0; i <= n; i++)
	{
		ans = max(ans, f[i] + g[i + 1]);
	}
	cout << ans << endl;
	return 0;
}