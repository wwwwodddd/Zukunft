#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int f[100020][3][3][3][3][3];
void inc(int &x, int y)
{
	x = (x + y) % p;
}
int main()
{
	int n = 100000;
	f[1][1][0][2][0][0] = 3;
	f[1][0][1][1][1][0] = 3;
	f[1][0][2][1][0][1] = 3;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int r0 = 0; r0 < 3; r0++)
				{
					for (int r1 = 0; r1 < 3; r1++)
					{
						for (int r2 = 0; r2 < 3; r2++)
						{
							for (int d = 0; d < 10; d++)
							{
								if ((k + d) % 3 == 0)
								{
									inc(f[i + 1][(j + r0) % 3][(k + d) % 3][(r0 + 1) % 3][r1][r2], f[i][j][k][r0][r1][r2]);
								}
								else if ((k + d) % 3 == 1)
								{
									inc(f[i + 1][(j + r1) % 3][(k + d) % 3][r0][(r1 + 1) % 3][r2], f[i][j][k][r0][r1][r2]);
								}
								else if ((k + d) % 3 == 2)
								{
									inc(f[i + 1][(j + r2) % 3][(k + d) % 3][r0][r1][(r2 + 1) % 3], f[i][j][k][r0][r1][r2]);
								}
							}
						}
					}
				}
			}
		}
	}
	int z = 0;
	for (int k = 0; k < 3; k++)
	{
		for (int r0 = 0; r0 < 3; r0++)
		{
			for (int r1 = 0; r1 < 3; r1++)
			{
				for (int r2 = 0; r2 < 3; r2++)
				{
					inc(z, f[n][0][k][r0][r1][r2]);
				}
			}
		}
	}
	printf("%d\n", z);
	return 0;
}