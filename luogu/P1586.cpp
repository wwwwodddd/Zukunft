#include <bits/stdc++.h>
using namespace std;
int t, n;
int f[5][33000];
int main()
{
	f[0][0] = 1;
	for (int i = 1; i * i < 33000; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = i * i; k < 33000; k++)
			{
				f[j + 1][k] += f[j][k - i * i];
			}
		}
	}
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		printf("%d\n", f[1][n] + f[2][n] + f[3][n] + f[4][n]);
	}
	return 0;
}