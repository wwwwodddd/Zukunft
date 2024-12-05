#include <bits/stdc++.h>
using namespace std;
int m, n, x, y, z;
int v[10020];
int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		for (int j = x; j <= y; j++)
		{
			v[j] = 1;
		}
	}
	for (int i = 0; i <= m; i++)
	{
		if (v[i] == 0)
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}