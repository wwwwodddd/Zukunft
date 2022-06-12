#include <bits/stdc++.h>
using namespace std;
long long x, a, d, n, b;
int main()
{
	cin >> x >> a >> d >> n;
	b = a + d * (n - 1);
	if (d < 0)
	{
		swap(a, b);
		d = -d;
	}
	if (x <= a)
	{
		cout << a - x << endl;
	}
	else if (x >= b)
	{
		cout << x - b << endl;
	}
	else
	{
		x = (x - a) % d;
		cout << min(x, d - x) << endl;
	}
	return 0;
}
