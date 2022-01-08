#include <bits/stdc++.h>
using namespace std;
int n, m;
string a[50];
string b[50];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i + m <= n; i++)
	{
		for (int j = 0; j + m <= n; j++)
		{
			int f = 1;
			for (int k = 0; k < m; k++)
			{
				for (int l = 0; l < m; l++)
				{
					if (b[k][l] != a[i + k][j + l])
					{
						f = 0;
					}
				}
			}
			if (f)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
