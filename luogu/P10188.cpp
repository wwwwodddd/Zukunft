#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
int a[200020];
int b[200020];
int d[200020];
void dfs(int x, int y)
{
	if (d[x] == 1)
	{
		return;
	}
	if (a[x] >= y)
	{
		a[x] -= y;
	}
	else
	{
		if (s[x] == 'L')
		{
			dfs((x + n - 1) % n, y - a[x]);
		}
		else
		{
			dfs((x + n + 1) % n, y - a[x]);
		}
		a[x] = 0;
	}
}
int main()
{
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
		d[i]--;
		if (s[i] == 'L')
		{
			d[(i + n - 1) % n]++;
		}
		else
		{
			d[(i + n + 1) % n]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (d[i] == -1)
		{
			dfs(i, m);
		}
	}
	long long s = 0;
	for (int i = 0 ; i < n; i++)
	{
		s += a[i];
	}
	cout << s << endl;
	return 0;
}
