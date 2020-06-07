#include <bits/stdc++.h>
using namespace std;
bitset<301>f[26];
int main()
{
	int n;
	cin >> n;
	f[0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i * (i - 1) / 2; j++)
		{
			if (f[i][j])
			{
				for (int k = 0; i + k <= n; k++)
				{
					f[i + k][j + k * (k - 1) / 2] = true;
				}
			}
		}
	}
	cout << f[n].count() << endl;
	return 0;
}