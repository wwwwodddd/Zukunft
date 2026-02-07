#include <bits/stdc++.h>
using namespace std;
int n, x, a, b, c, d;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x < 60)
		{
			d++;
		}
		else if (x < 80)
		{
			c++;
		}
		else if (x < 90)
		{
			b++;
		}
		else
		{
			a++;
		}
	}
	cout << a << '\n' << b << '\n' << c << '\n' << d << '\n';
	return 0;
}