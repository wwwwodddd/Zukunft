#include <bits/stdc++.h>
using namespace std;
int n, z;
int x[1020];
int y[1020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++)
	{
		map<pair<int, int>, int> h;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			int g = abs(__gcd(dx, dy));
			dx /= g;
			dy /= g;
			z = max(z, ++h[{dx, dy}]);
		}
	}
	cout << z + 1 << endl;
	return 0;
}