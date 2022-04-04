#include <bits/stdc++.h>
using namespace std;
int n;
double f[1251][1251];
int main()
{
	cin >> n;
	n /= 2;
	f[0][0] = 1;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i < n && j < n)
			{
				f[i][j + 1] += f[i][j] / 2;
				f[i + 1][j] += f[i][j] / 2;
			}
			else if (i < n && j == n)
			{
				f[i + 1][j] += f[i][j];
			}
			else if (i == n && j < n)
			{
				f[i][j + 1] += f[i][j];
			}
//			printf("%.6f ", f[i][j]);
		}
//		printf("\n");
	}
	double z = 0;
	if (n >= 2)
	{
		z = f[n - 2][n] + f[n][n - 2];
	}
	cout << fixed << setprecision(4) << z << endl;
	return 0;
}
