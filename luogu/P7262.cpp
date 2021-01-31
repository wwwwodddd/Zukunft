#include <bits/stdc++.h>
using namespace std;
int n, m, x;
char c;
char s[120][120];
int main()
{
	scanf("%d%d %c", &n, &m, &c);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
		if (c == '<')
		{
			reverse(s[i], s[i] + m);
		}
	}
	if (c == '^')
	{
		reverse(s, s + n);
	}
	if (c == '<' || c == '>')
	{
		for (int i = 0; i < n; i++)
		{
			int o = 0;
			for (int j = 0; j < m; j++)
			{
				if (s[i][j] == 'o')
				{
					o = 1;
				}
				else if (s[i][j] == 'x' && o)
				{
					x = 1;
				}
			}
		}
	}
	else
	{
		for (int j = 0; j < m; j++)
		{
			int o = 0;
			for (int i = 0; i < n; i++)
			{
				if (s[i][j] == 'o')
				{
					o = 1;
				}
				else if (s[i][j] == 'x' && o)
				{
					x = 1;
				}
			}
		}
	}
	puts(x ? "GG" : "OK");
	return 0;
}