#include <bits/stdc++.h>
using namespace std;
int n, a, x, y, xi, yi, l;
long long z;
int main()
{
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (a == x)
		{
			xi = i;
		}
		if (a == y)
		{
			yi = i;	
		}
		if (a < y || a > x)
		{
			xi = 0;
			yi = 0;
			l = i;
		}
		if (xi && yi)
		{
			z += min(xi, yi) - l;
		}
	}
	cout << z << endl;
	return 0;
}
