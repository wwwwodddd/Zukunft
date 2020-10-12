#include <bits/stdc++.h>
using namespace std;
int n, f[10020];
int main()
{
	scanf("%d", &n);
	f[0] = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = n; j > 0; j--)
		{
			for (int k = 1; k * k <= j; k++)
			{
				f[j] += f[j - k * k];
			}
		}
	}
	printf("%d\n", f[n]);
	return 0;
}