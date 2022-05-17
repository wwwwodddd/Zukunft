#include <bits/stdc++.h>
using namespace std;
int n, m, x, lmx, lmxi, rmx, rmxi;
int main()
{
	cin >> n;
	m = 1 << n - 1;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		if (lmx < x)
		{
			lmx = x;
			lmxi = i;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		if (rmx < x)
		{
			rmx = x;
			rmxi = i;
		}
	}
	if (lmx < rmx)
	{
		cout << lmxi + 1 << endl;
	}
	else
	{
		cout << rmxi + 1 + m << endl;
	}
	return 0;
}
