#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	string z;
	int s = 0, zg = 0;
	for (int i = 0; i < n; i++)
	{
		string a;
		int b, c;
		char d, e;
		int f, g = 0;
		cin >> a >> b >> c >> d >> e >> f;
		if (b > 80 && f > 0)
		{
			g += 8000;
		}
		if (b > 85 && c > 80)
		{
			g += 4000;
		}
		if (b > 90)
		{
			g += 2000;
		}
		if (b > 85 && e == 'Y')
		{
			g += 1000;
		}
		if (c > 80 && d == 'Y')
		{
			g += 850;
		}
		if (zg < g)
		{
			zg = g;
			z = a;
		}
		s += g;
	}
	cout << z << endl;
	cout << zg << endl;
	cout << s << endl;
	return 0;
}