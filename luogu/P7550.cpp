#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[1020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (s[i][j] == '#')
			{
				s[i][j + 1] = '#';
				s[i + 1][j] = '#';
				s[i + 1][j + 1] = '#';
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << s[i] << endl;
	}
	return 0;
}
