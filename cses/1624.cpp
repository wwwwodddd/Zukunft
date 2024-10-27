#include <bits/stdc++.h>
using namespace std;
int xplusy[30], xminusy[30], y[30], a[30];
int n = 8, cnt;
char s[10][10];
void dfs(int x)
{
	if (x == n)
	{
		cnt++;
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (s[x][i] == '.' && y[i] == 0 && xplusy[x + i] == 0 && xminusy[x - i + n] == 0)
			{
				a[x] = i;
				y[i] = 1;
				xplusy[x + i] = 1;
				xminusy[x - i + n] = 1;
				dfs(x + 1);
				xminusy[x - i + n] = 0;
				xplusy[x + i] = 0;
				y[i] = 0;
				a[x] = 0;
			}
		}
	}
}
int main()
{
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	dfs(0);
	cout << cnt << endl;
	return 0;
}