#include <bits/stdc++.h>
using namespace std;
int n, m, x, c, a;
int main()
{
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		if (a < x)
		{
			c++;
		}
	}
	cout << min(c, m - c) << endl;
	return 0;
}
