#include <bits/stdc++.h>
using namespace std;
string s;
int n, z, a[256], b[256];
char c, x, y;
int main()
{
	a['A'] = 11;
	a['K'] = 4;
	a['Q'] = 3;
	a['J'] = 20;
	a['T'] = 10;
	a['9'] = 14;
	a['8'] = 0;
	a['7'] = 0;
	b['A'] = 11;
	b['K'] = 4;
	b['Q'] = 3;
	b['J'] = 2;
	b['T'] = 10;
	b['9'] = 0;
	b['8'] = 0;
	b['7'] = 0;
	cin >> n >> c;
	for (int i = 0; i < 4 * n; i++)
	{
		cin >> x >> y;
		if (y == c)
		{
			z += a[x];
		}
		else
		{
			z += b[x];
		}
	}
	cout << z << endl;
	return 0;
}
