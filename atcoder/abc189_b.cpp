#include <bits/stdc++.h>
using namespace std;
int n, x, v, p;
int main()
{
	cin >> n >> x;
	x *= 100;
	for (int i = 1; i <= n; i++)
	{
		cin >> v >> p;
		if (x >= v * p)
		{
			x -= v * p;
		}
		else
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
