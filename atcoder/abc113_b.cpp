#include <bits/stdc++.h>
using namespace std;
int n, t, a, h, z, zi;
int main()
{
	cin >> n >> t >> a;
	z = 1e9;
	for (int i = 1; i <= n; i++)
	{
		cin >> h;
		if (z > abs((t - a) * 1000 - h * 6))
		{
			z = abs((t - a) * 1000 - h * 6);
			zi = i;
		}
	}
	cout << zi << endl;
	return 0;
}
