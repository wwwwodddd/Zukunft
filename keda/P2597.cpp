#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
int a[3020][3020];
int b[3020][3020];
int c[3020][3020];
int v[3020][3020];
queue<int> q;
void inc(int x, int y, int da, int db, int dc)
{
	a[x][y] += da;
	b[x][y] += db;
	c[x][y] += dc;
	if (a[x][y] == 13 && v[5 * x - b[x][y]][5 * y - c[x][y]] == 0)
	{
		z++;
		q.push(5 * x - b[x][y]);
		q.push(5 * y - c[x][y]);
		v[5 * x - b[x][y]][5 * y - c[x][y]] = 1;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		x += 1000;
		y += 1000;
		if (a[x][y] >= 10)
		{
			z--;
		}
		else
		{
			q.push(x);
			q.push(y);
			v[x][y] = 1;
			while (q.size())
			{
				x = q.front();
				q.pop();
				y = q.front();
				q.pop();
				inc(x, y, 10, x, y);
				inc(x + 1, y, 1, x, y);
				inc(x - 1, y, 1, x, y);
				inc(x, y + 1, 1, x, y);
				inc(x, y - 1, 1, x, y);
			}
		}
		printf("%d\n", z);
	}
	return 0;
}