#include <bits/stdc++.h>
using namespace std;
int n, m, f;
int b[10020][7];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			if (b[i][j] != b[0][0] + 7 * i + j)
			{
				f = 1;
			}
		}
	}
	if ((b[0][0] - 1) / 7 != (b[0][m - 1] - 1) / 7)
	{
		f = 1;
	}
	cout << (f ? "No" : "Yes") << endl;
	return 0;
}
