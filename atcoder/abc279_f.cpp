#include <bits/stdc++.h>
using namespace std;
int n, m, q, o, x, y;
int f[1000020];
int d[1000020]; // box i -> set d[i]
int c[1000020]; // set i -> box c[i]
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		d[i] = i;
		c[i] = i;
	}
	m = n + q;
	for (int i = 0; i < q; i++)
	{
		cin >> o >> x;
		if (o == 1)
		{
			cin >> y;
			f[F(d[y])] = F(d[x]);
			m++;
			f[m] = m;
			d[y] = m;
			c[m] = y;
		}
		else if (o == 2)
		{
			n++;
			f[n] = F(d[x]);
		}
		else
		{
			cout << c[F(x)] << endl;
		}
	}
	return 0;
}
