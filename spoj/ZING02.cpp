#include <bits/stdc++.h>
using namespace std;
int t;
long long l, r;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> l >> r;
		r -= l - 1;
		if (r == 1)
		{
			r = 3;
		}
		l = 1LL << (63 - __builtin_clzll(r));
		cout << min(r - l, 2 * l - r) << endl;
	}
	return 0;
}