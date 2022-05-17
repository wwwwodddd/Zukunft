#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[60][60];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i] + 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s[i][j] == '#' && s[i-1][j] != '#' && s[i+1][j] !='#' && s[i][j-1] != '#' && s[i][j+1] != '#')
			{
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}