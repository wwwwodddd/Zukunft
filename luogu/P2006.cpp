#include <bits/stdc++.h>
using namespace std;
int k, m, n, a, b, c;
int main()
{
	cin >> k >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		if ((a == 0 && b > 0) || (a > 0 && (long long)k / a * b >= n))
		{
			c++;
			cout << i << ' ';
		}
	}
	if (!c)
	{
		cout << -1;
	}
	cout << endl;
	return 0;
}