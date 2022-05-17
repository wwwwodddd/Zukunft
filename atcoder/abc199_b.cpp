#include <bits/stdc++.h>
using namespace std;
int n, x, mn = 1000, mx = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		mx = max(mx, x);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		mn = min(mn, x);
	}
	cout << max(mn - mx + 1, 0) << endl;
	return 0;
}
