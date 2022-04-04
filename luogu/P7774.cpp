#include <bits/stdc++.h>
using namespace std;
int n, m, x, g = 360;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		g = __gcd(g, x);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		cout << (x % g ? "NO" : "YES") << endl;
	}
	return 0;
}
