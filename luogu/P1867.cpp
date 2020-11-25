#include <bits/stdc++.h>
using namespace std;
int n, x, s = 1;
double h = 10, d;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> d >> x;
		h = min(h - d, 10.);
		if (h <= 0)
		{
			break;
		}
		s += x;
	}
	cout << 31 - __builtin_clz(s) << ' ' << s - (1 << (31 - __builtin_clz(s))) << endl;
	return 0;
}