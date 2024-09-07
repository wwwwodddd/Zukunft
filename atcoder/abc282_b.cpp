#include <bits/stdc++.h>
using namespace std;
int n, m, z;
string s[40];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			int c = 0;
			for (int k = 0; k < m; k++)
			{
				if (s[i][k] == 'x' && s[j][k] == 'x')
				{
					c++;
					break;
				}
			}
			if (c == 0)
			{
				z++;
			}
		}
	}
	cout << z << endl;
	return 0;
}
