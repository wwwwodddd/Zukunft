#include <bits/stdc++.h>
using namespace std;
int n, x, mx, mxi, mx2, mx2i;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		if (mx < x)
		{
			mx2 = mx;
			mx2i = mxi;
			mx = x;
			mxi = i;
		}
		else if (mx2 < x)
		{
			mx2 = x;
			mx2i = i;
		}
	}
	cout << mx2i << endl;
	return 0;
}