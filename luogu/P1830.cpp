#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int a[120][120];
int b[120][120];
int main()
{
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 1; i <= x; i++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for (int j = x1; j <= x2; j++)
		{
			for (int k = y1; k <= y2; k++)
			{
				a[j][k]++;
				b[j][k] = i;
			}
		}
	}
	for (int i = 0; i < y; i++)
	{
		cin >> x1 >> y1;
		if (a[x1][y1])
		{
			printf("Y %d %d\n", a[x1][y1], b[x1][y1]);
		}
		else
		{
			printf("N\n");
		}
	}
	return 0;
}