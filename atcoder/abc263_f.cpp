#include <bits/stdc++.h>
using namespace std;
int n;
long long c[17][65537];
long long z;
int main()
{
	cin >> n;
	for (int j = 0; j < 1 << n; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 1 << n; j += 1 << i)
		{
			long long t = -1e18;
			for (int k = 0; k < 1 << i; k++)
			{
				t = max(t, c[i][j + k]);
			}
			for (int k = 0; k < 1 << i; k++)
			{
				for (int l = i + 1; l <= n; l++)
				{
					c[l][j + k] -= t;				
				}
			}
			z += t;
		}
	}
	cout << z << endl;
	return 0;
}
