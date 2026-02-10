#include <bits/stdc++.h>
using namespace std;
int n, x, y, z, c;
int d[120];
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		d[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)
		{
			c++;
			z = i;
		}
	}
	if (c > 1)
	{
		z = -1;
	}
	cout << z << endl;
	return 0;
}