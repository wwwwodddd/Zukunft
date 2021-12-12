#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		long long a, b, c, d, s = 0;
		cin >> a >> b >> c;
		// 4 3 3
		d = min(b / 2, c);
		b -= d * 2;
		c -= d;
		s += d;

		// 4 4 2
		d = min(a, c / 2);
		a -= d;
		c -= d * 2;
		s += d;

		// 3 3 2 2
		d = min(a / 2, b / 2);
		a -= d * 2;
		b -= d * 2;
		s += d;

		// 4 2 2 2
		d = min(a / 3, c);
		a -= d * 3;
		c -= d;
		s += d;
		
		// 2 2 2 2 2
		d = a / 5;
		a -= d * 5;
		s += d;

		cout << s << endl;
	}
}
