#include <bits/stdc++.h>
using namespace std;
int n, m, ac, bc, sa, sb, z, x, y, v;
int a[1000020];
int b[1000020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		for (int j = 0; j < y; j++)
		{
			a[ac++] = x;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		for (int j = 0; j < y; j++)
		{
			b[bc++] = x;
		}
	}
	v = a[0] > b[0];
	for (int i = 0; i < min(ac, bc); i++)
	{
		sa += a[i];
		sb += b[i];
		if (sa > sb && v == 0)
		{
			z++;
			v = 1;
		}
		if (sa < sb && v == 1)
		{
			z++;
			v = 0;
		}
	}
	cout << z << endl;
	return 0;
}