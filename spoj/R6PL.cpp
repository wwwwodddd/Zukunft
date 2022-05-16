#include <bits/stdc++.h>
using namespace std;
int t, n, x, y, d;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		bitset<100001> f;
		cin >> n;
		f[50000] = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			d = abs(x - y);
			f = f << d | f >> d;
		}
		for (int i = 0; i <= 250; i++)
		{
			if (f[50000 + i])
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}