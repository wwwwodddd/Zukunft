#include <bits/stdc++.h>
using namespace std;
int n;
long long x, a, b, c;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a += abs(x);
		b += x * x;
		c = max(c, abs(x));
	}
	cout << a << endl;
	cout << fixed << setprecision(9) << sqrt(b) << endl;
	cout << c << endl;
	return 0;
}
