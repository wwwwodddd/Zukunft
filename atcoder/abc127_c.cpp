#include <bits/stdc++.h>
using namespace std;
int n, m, l, r, x, y;
int main()
{
	cin >> n >> m;
	x = 1;
	y = n;
	for (int i = 0; i < m; i++)
	{
		cin >> l >> r;
		x = max(x, l);
		y = min(y, r);
	}
	cout << max(y - x + 1, 0) << endl;
	return 0;
}
