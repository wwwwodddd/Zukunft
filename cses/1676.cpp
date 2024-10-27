#include <bits/stdc++.h>
using namespace std;
int f[100020];
int c[100020];
int n, m, s, t;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> n >> m;
	s = n;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		c[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x = F(x);
		y = F(y);
		if (x != y)
		{
			f[x] = y;
			c[y] += c[x];
			s--;
			t = max(t, c[y]);
		}
		cout << s << " " << t << endl;
	}
	return 0;
}