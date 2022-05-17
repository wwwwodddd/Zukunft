#include <bits/stdc++.h>
using namespace std;
int n;
string s[1000];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		int c = (s[i][0] == '#') + (s[i][1] == '#') + (s[i][2] == '#') + (s[i][3] == '#') + (s[i][4] == '#');
		for (int j = 5; j < n; j++)
		{
			c += (s[i][j] == '#');
			if (c >= 4)
			{
				cout << "Yes" << endl;
				return 0;
			}
			c -= (s[i][j - 5] == '#');
		}
	}
	for (int i = 0; i < n; i++)
	{
		int c = (s[0][i] == '#') + (s[1][i] == '#') + (s[2][i] == '#') + (s[3][i] == '#') + (s[4][i] == '#');
		for (int j = 5; j < n; j++)
		{
			c += (s[j][i] == '#');
			if (c >= 4)
			{
				cout << "Yes" << endl;
				return 0;
			}
			c -= (s[j - 5][i] == '#');
		}
	}
	for (int i = 5; i < n; i++)
	{
		for (int j = 5; j < n; j++)
		{
			int c = 0;
			for (int k = 0; k <= 5; k++)
			{
				if (s[i - k][j - k] == '#')
				{
					c++;
				}
			}
			if (c >= 4)
			{
				cout << "Yes" << endl;
				return 0;
			}
			c = 0;
			for (int k = 0; k <= 5; k++)
			{
				if (s[i - k][j - 5 + k] == '#')
				{
					c++;
				}
			}
			if (c >= 4)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
