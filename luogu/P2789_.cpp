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
			for (int k = 1; f[i][j] && i + k <= n; k++)
			{
				f[i + k][j + k * i] = 1;
			}
		}
	}
	cout << f[n].count() << endl;
	return 0;
}