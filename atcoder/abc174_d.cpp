#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
string s;
int main()
{
	cin >> n >> s;
	for (char i: s)
	{
		if (i == 'R')
		{
			y++;
		}
	}
	z = max(x, y);
	for (char i: s)
	{
		if (i == 'R')
		{
			y--;
		}
		else
		{
			x++;
		}
		z = min(z, max(x, y));
	}
	cout << z << endl;
	return 0;
}
