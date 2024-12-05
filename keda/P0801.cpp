#include <bits/stdc++.h>
using namespace std;
int n, a[9];
void dfs(int x, int y, int z)
{
	if (y == 0)
	{
		if (x > 1)
		{
			for (int i = 0; i < x; i++)
			{
				printf("%d%c", a[i], i == x - 1 ? '\n' : '+');
			}
		}
		return;
	}
	for (int i = z; i <= y; i++)
	{
		a[x] = i;
		dfs(x + 1, y - i, i);
	}
}
int main()
{

	scanf("%d", &n);
	dfs(0, n, 1);
	return 0;
}