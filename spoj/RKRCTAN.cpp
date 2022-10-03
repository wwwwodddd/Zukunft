#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int t;
long long a, b, c, d, e;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b >> c >> d;
		a %= p;
		b %= p;
		c %= p;
		d %= p;
		e = a * b - c * d;
		e %= p;
		if (e < 0)
		{
			e += p;
		}
		cout << e << endl;
	}
	return 0;
}