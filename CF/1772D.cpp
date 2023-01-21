#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int dn = 0, up = 1e9;
		for (int i = 1; i < n; i++)
		{
			if (a[i - 1] > a[i])
			{
				dn = max(dn, (a[i - 1] + a[i] + 1) / 2);
			}
			else if (a[i - 1] < a[i])
			{
				up = min(up, (a[i - 1] + a[i]) / 2);
			}
		}
		if (dn <= up)
		{
			cout << dn << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}