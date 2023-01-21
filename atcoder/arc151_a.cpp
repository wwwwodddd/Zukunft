#include <bits/stdc++.h>
using namespace std;
int n, c, x, y;
string s, t;
int main()
{
	cin >> n >> s >> t;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != t[i])
		{
			c++;
		}
	}
	if (c & 1)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i] == t[i])
		{
			cout << 0;
		}
		else if (s[i] == '0')
		{
			if (y < c / 2)
			{
				cout << 0;
				y++;
			}
			else
			{
				cout << 1;
				x++;
			}
		}
		else if (t[i] == '0')
		{
			if (x < c / 2)
			{
				cout << 0;
				x++;
			}
			else
			{
				cout << 1;
				y++;
			}
		}
		else
		{
			assert(false);
		}
	}
	cout << endl;
	return 0;
}