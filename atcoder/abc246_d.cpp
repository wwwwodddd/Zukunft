#include <bits/stdc++.h>
using namespace std;
long long n, a, b, x, z = 1e18;
int main()
{
	cin >> n;
	b = cbrt(n) + 1;
	while (a <= b)
	{
		x = a * a * a + a * a * b + a * b * b + b * b * b;
		if (x >= n)
		{
			z = min(z, x);
			b--;
		}
		else
		{
			a++;
		}
	}
	cout << z << endl;
	return 0;
}
