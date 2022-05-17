#include <bits/stdc++.h>
using namespace std;
int n, m, z;
string s[100];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.')
			{
				if (i > 0 && s[i - 1][j] == '.')
				{
					z++;
				}
				if (j > 0 && s[i][j - 1] == '.')
				{
					z++;
				}
			}
		}
	}
	cout << z << endl;
	return 0;
}
