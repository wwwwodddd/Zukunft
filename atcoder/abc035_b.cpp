#include <bits/stdc++.h>
using namespace std;
string s;
int x, y, c, t;
int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'L')
		{
			x--;
		}
		else if (s[i] == 'R')
		{
			x++;
		}
		else if (s[i] == 'D')
		{
			y--;
		}
		else if (s[i] == 'U')
		{
			y++;
		}
		else
		{
			c++;
		}
	}
	cin >> t;
	x = abs(x);
	y = abs(y);
	if (t == 1)
	{
		cout << x + y + c << endl;
	}
	else
	{
		if (x + y > c)
		{
			cout << x + y - c << endl;
		}
		else
		{
			cout << (c - x + y) % 2 << endl;
		}
	}
}
