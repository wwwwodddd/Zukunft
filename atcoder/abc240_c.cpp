#include <bits/stdc++.h>
using namespace std;
int n, x, a, b;
int f[101][10120];
int main()
{
	f[0][0] = 1;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		for (int j = 0; j <= x; j++)
		{
			if (f[i][j])
			{
				f[i + 1][j + a] = 1;
				f[i + 1][j + b] = 1;
			}
		}
	}
	cout << (f[n][x] ? "Yes" : "No") << endl;
	return 0;
}
