#include <bits/stdc++.h>
using namespace std;
int t, n, m, x, y, s, ac, bc;
char c;
pair<int, int> a[5020];
pair<int, int> b[5020];
int **f;
int **g;
int **h;
int fm[10020];
int gm[10020];
int fd[10020];
int gd[10020];
int fgm[10020];
int fhm[10020];
int gfm[10020];
int ghm[10020];
// f[i][j]   i没匹配 j匹配了
// g[i][j]   i匹配了 j没匹配

bool inpair(int x, int y)
{
	return 0 < x && x <= ac && 0 < y && y <= bc && abs(a[x].first - b[y].first) <= m;
}
bool unpair(int x, int y)
{
	return x == 0 || x == ac + 1 || y == 0 || y == bc + 1 || abs(a[x].first - b[y].first) > m;
}
int main()
{
	cin >> t >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> c >> x >> y;
		s += y;
		if (c == 'H')
		{
			a[++ac] = make_pair(x, y);
		}
		else
		{
			b[++bc] = make_pair(x, y);
		}
	}
	// for (int i = 1; i <= ac; i++)
	// {
	// 	printf("(%d, %d), ", a[i].first, a[i].second);
	// }
	// printf("\n");
	// for (int i = 1; i <= bc; i++)
	// {
	// 	printf("(%d, %d), ", b[i].first, b[i].second);
	// }
	// printf("\n");
	if (t == 1)
	{
		f = new int *[ac + 2];
		for (int i = 0; i < ac + 2; i++)
		{
			f[i] = new int[bc + 2];
			for (int j = 0; j < bc + 2; j++)
			{
				f[i][j] = 0;
			}
		}

		for (int i = 1; i <= ac; i++)
		{
			for (int j = 1; j <= bc; j++)
			{
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				if (abs(a[i].first - b[j].first) <= m)
				{
					f[i][j] = max(f[i][j], f[i - 1][j - 1] + a[i].second + b[j].second);
				}
			}
		}
		cout << s - f[ac][bc] << endl;
		return 0;
	}
	f = new int *[ac + 2];
	g = new int *[ac + 2];
	h = new int *[ac + 2];
	for (int i = 0; i < ac + 2; i++)
	{
		f[i] = new int[bc + 2];
		g[i] = new int[bc + 2];
		h[i] = new int[bc + 2];
		for (int j = 0; j < bc + 2; j++)
		{
			f[i][j] = -1e9;
			g[i][j] = -1e9;
			h[i][j] = -1e9;
		}
	}
	memset(fm, 0xc0, sizeof fm);
	memset(gm, 0xc0, sizeof gm);
	memset(fgm, 0xc0, sizeof fgm);
	memset(fhm, 0xc0, sizeof fhm);
	memset(gfm, 0xc0, sizeof gfm);
	memset(ghm, 0xc0, sizeof ghm);
	f[0][0] = 0;
	g[0][0] = 0;
	h[0][0] = 0;
	a[0].first = -m - 1;
	b[0].first = -m - 2;
	a[ac + 1].first = 1e9 + m + 2;
	b[bc + 1].first = 1e9 + m + 1;
	for (int i = 0; i <= ac + 1; i++)
	{
		for (int j = 0; j <= bc + 1; j++)
		{
			if (i > 0)
			{
				f[i][j] = max(f[i][j], f[i - 1][j] + a[i].second);
			}

			if (j > 0)
			{
				g[i][j] = max(g[i][j], g[i][j - 1] + b[j].second);
			}

			if (i > 0 && a[i].first > b[j].first)
			{
				if (unpair(i, j)) // 如果 i 和 j 都没匹配
				{
					h[i][j] = max(h[i][j], h[i - 1][j] + a[i].second);
					h[i][j] = max(h[i][j], g[i - 1][j] + a[i].second);
				}
			}

			if (j > 0 && a[i].first < b[j].first)
			{
				if (unpair(i, j)) // 如果 i 和 j 都没匹配
				{
					h[i][j] = max(h[i][j], h[i][j - 1] + b[j].second);
					h[i][j] = max(h[i][j], f[i][j - 1] + b[j].second);
				}
			}
			// 对于 f[i][j]
			// i-1 匹配 j
			// i-2 匹配 j-1
			// ...
			// i-d 匹配 j-d+1
			if (inpair(i - 1, j))
			{
				fm[n + i - 1 - j] = max(fm[n + i - 1 - j], f[i - 2][j - 1]);
				// printf("fd[%d]=%d\n", n + i - 1 - j, fd[n + i - 1 - j]);
				while (fd[n + i - 1 - j] < j && unpair(i, fd[n + i - 1 - j]))
				{
					// printf("newupd fghm[%d]  with gh[%d][%d]\n", n + i - 1 - j, i - (j - fd[n + i - 1 - j]) - 1, fd[n + i - 1 - j]);
					fgm[n + i - 1 - j] = max(fgm[n + i - 1 - j], g[i - (j - fd[n + i - 1 - j]) - 1][fd[n + i - 1 - j]]);
					fhm[n + i - 1 - j] = max(fhm[n + i - 1 - j], h[i - (j - fd[n + i - 1 - j]) - 1][fd[n + i - 1 - j]]);
					fd[n + i - 1 - j]++;
				}
			}
			else
			{
				fm[n + i - 1 - j] = -1e9;
				fd[n + i - 1 - j] = j;
				fgm[n + i - 1 - j] = -1e9;
				fhm[n + i - 1 - j] = -1e9;
			}
			f[i][j] = max(f[i][j], fm[n + i - 1 - j] + a[i].second);
			f[i][j] = max(f[i][j], fgm[n + i - 1 - j] + a[i].second);
			f[i][j] = max(f[i][j], fhm[n + i - 1 - j] + a[i].second);
			// for (int d = 1; d < i && d <= j; d++)
			// {
			// 	if (inpair(i - d, j - d + 1))
			// 	{
			// 		if (unpair(i, j - d))
			// 		{
			// 			printf("----------oldupd f[%d][%d]  with gh[%d][%d]\n", i, j, i - d - 1, j - 1);
			// 			f[i][j] = max(f[i][j], g[i - d - 1][j - d] + a[i].second);
			// 			f[i][j] = max(f[i][j], h[i - d - 1][j - d] + a[i].second);
			// 		}
			// 	}
			// 	else
			// 	{
			// 		printf("breakwhen %d %d\n", i-d, i-d+1);
			// 		break;
			// 	}
			// }
			// 对于 g[i][j]
			// i 匹配 j-1
			// i-1 匹配 j-2
			// ...
			// i-d+1 匹配 j-d
			if (inpair(i, j - 1))
			{
				gm[n + i + 1 - j] = max(gm[n + i + 1 - j], g[i - 1][j - 2]);
				while (gd[n + i + 1 - j] < i && unpair(gd[n + i + 1 - j], j))
				{
					// printg("newupd gghm[%d]  with gh[%d][%d]\n", n + i + 1 - j, i - (j - gd[n + i + 1 - j]) - 1, gd[n + i + 1 - j]);
					gfm[n + i + 1 - j] = max(gfm[n + i + 1 - j], f[gd[n + i + 1 - j]][j - (i - gd[n + i + 1 - j]) - 1]);
					ghm[n + i + 1 - j] = max(ghm[n + i + 1 - j], h[gd[n + i + 1 - j]][j - (i - gd[n + i + 1 - j]) - 1]);
					gd[n + i + 1 - j]++;
				}
			}
			else
			{
				gm[n + i + 1 - j] = -1e9;
				gd[n + i + 1 - j] = i;
				gfm[n + i + 1 - j] = -1e9;
				ghm[n + i + 1 - j] = -1e9;
			}
			g[i][j] = max(g[i][j], gm[n + i + 1 - j] + b[j].second);
			g[i][j] = max(g[i][j], gfm[n + i + 1 - j] + b[j].second);
			g[i][j] = max(g[i][j], ghm[n + i + 1 - j] + b[j].second);
			// for (int d = 1; d <= i && d < j; d++)
			// {
			// 	if (inpair(i - d + 1, j - d))
			// 	{
			// 		if (unpair(i - d, j))
			// 		{
			// 			g[i][j] = max(g[i][j], f[i - d][j - d - 1] + b[j].second);
			// 			g[i][j] = max(g[i][j], h[i - d][j - d - 1] + b[j].second);
			// 		}
			// 	}
			// 	else
			// 	{
			// 		break;
			// 	}
			// }
		}
	}
	// printf("f[][]\n");
	// for (int i = 0; i <= ac + 1; i++)
	// {
	// 	for (int j = 0; j <= bc + 1; j++)
	// 	{
	// 		printf("%12d ", f[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("g[][]\n");
	// for (int i = 0; i <= ac + 1; i++)
	// {
	// 	for (int j = 0; j <= bc + 1; j++)
	// 	{
	// 		printf("%12d ", g[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("h[][]\n");
	// for (int i = 0; i <= ac + 1; i++)
	// {
	// 	for (int j = 0; j <= bc + 1; j++)
	// 	{
	// 		printf("%12d ", h[i][j]);
	// 	}
	// 	printf("\n");
	// }
	cout << h[ac + 1][bc + 1] << endl;
	return 0;
}