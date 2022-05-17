#include <bits/stdc++.h>
using namespace std;
int n, m, x, mn = 100, s;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n * m; i++)
	{
		cin >> x;
		mn = min(mn, x);
		s += x;
	}
	cout << s - mn * n * m << endl;
	return 0;
}
