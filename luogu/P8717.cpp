#include <bits/stdc++.h>
using namespace std;
int n, x, mx, mn, sm;
int main()
{
	mn = 100;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		mx = max(mx, x);
		mn = min(mn, x);
		sm += x;
	}
	cout << mx << '\n'
		 << mn << '\n'
		 << fixed << setprecision(2) << double(sm) / n << '\n';
	return 0;
}