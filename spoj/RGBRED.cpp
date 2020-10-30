#include <bits/stdc++.h>
using namespace std;
int t, n, ss;
char s[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%s", &n, s);
		int c[3] = {};
		for (int i = 0; i < n; i++)
		{
			switch (s[i])
			{
				case 'R':
					c[0]++;
					break;
				case 'G':
					c[1]++;
					break;
				case 'B':
					c[2]++;
					break;
			}
		}
		sort(c, c + 3);
		if (c[1] == 0)
		{
			printf("%d\n", c[2]);
		}
		else
		{
			printf("%d\n", (c[1] - c[0]) % 2 == 0 && (c[2] - c[0]) % 2 == 0 ? 2 : 1);
		}
	}
	return 0;
}