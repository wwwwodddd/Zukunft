#include <bits/stdc++.h>
using namespace std;
int n, d, m, c;
int a[100020];
int main()
{
	cin >> n >> d >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		a[x] += z;
		a[y + 1] -= z;
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] += a[i - 1];
		if (a[i] < d)
		{
			c++;
		}
	}
	cout << c << endl;
	return 0;
}