#include <bits/stdc++.h>
using namespace std;
int a[99][4], n, m, W, I, N, G;
int f[202][202][4];
int g[202];
char s[202], o[9], c[5] = "WING";
int main()
{
	g['W'] = 0;
	g['I'] = 1;
	g['N'] = 2;
	g['G'] = 3;
	scanf("%d%d%d%d", &W, &I, &N, &G);
	for (; m < W + I + N + G; m++)
	{
		scanf("%s", o);
		a[m][0] = g[o[0]];
		a[m][1] = g[o[1]];
		if (m < W)
		{
			a[m][2] = 0;
		}
		else if (m < W + I)
		{
			a[m][2] = 1;
		}
		else if (m < W + I + N)
		{
			a[m][2] = 2;
		}
		else
		{
			a[m][2] = 3;
		}
	}
	scanf("%s", s);
	n = strlen(s);
	for (int i = n - 1; i >= 0; i--)
	{
		f[i][i + 1][g[s[i]]] = 1;
		for (int j = i + 2; j <= n; j++)
		{
			for (int k = i + 1; k < j; k++)
			{
				for (int l = 0; l < m; l++)
				{
					f[i][j][a[l][2]] |= f[i][k][a[l][0]] & f[k][j][a[l][1]];
				}
			}
		}
	}
	int z = 0;
	for (int i = 0; i < 4; i++)
	{
		if (f[0][n][i])
		{
			z++;
			cout << c[i];
		}
	}
	if (!z)
	{
		cout << "The name is wrong!";
	}
	cout << endl;
	return 0;
}