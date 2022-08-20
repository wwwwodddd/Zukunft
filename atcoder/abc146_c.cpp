#include <bits/stdc++.h>
using namespace std;
long long a, b, x, z;
int main()
{
	cin >> a >> b >> x;
	for (long long i = 1, j = 1; i < 1000000000; i *= 10, j++)
	{
		if (a * i + b * j <= x)
		{
			z = min((x - b * j) / a, 10 * i - 1);
		}
	}
	if (a * 1000000000 + b * 10 <= x)
	{
		z = 1000000000;
	}
	cout << z << endl;
	return 0;
}
