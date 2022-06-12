#include <bits/stdc++.h>
using namespace std;
int n, m, u, l, r, d;
char s[12][12];
int main()
{
	cin >> n >> m >> u >> l >> r >> d;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < u + n + d; i++)
	{
		for (int j = 0; j < l + m + r; j++)
		{
			if (u <= i && i < u + n && l <= j && j < l + m)
			{
				cout << s[i - u][j - l];
			}
			else
			{
				cout << ((i + j) & 1 ? '.' : '#');
			}
		}
		cout << endl;
	}
	return 0;
}
