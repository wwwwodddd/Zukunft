#include <bits/stdc++.h>
using namespace std;
int n, m, x, z;
int a[1020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> x;
			a[j] += x;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x == (a[i] > m / 2))
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
