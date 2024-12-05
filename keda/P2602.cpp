#include <bits/stdc++.h>
using namespace std;
int n, x, f, g;
int a[1020][2];
int b[1020][2];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &x);
			a[i][j % 2] += x;
			b[j][i % 2] += x;
		}
	}
	for (int i = 0; i < n; i++)
	{
		f += max(a[i][0], a[i][1]);
		g += max(b[i][0], b[i][1]);
	}
	printf("%d\n", max(f, g));
	return 0;
}