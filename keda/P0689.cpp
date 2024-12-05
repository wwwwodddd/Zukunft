#include <bits/stdc++.h>
using namespace std;
int p[2000020];
char c[1000020];
int main()
{
	scanf("%s", c);
	int n = strlen(c), s = n, z = 0;
	memset(p, -1, sizeof p);
	p[s] = 0;
	for (int i = 0; i < n; i++)
	{
		if (c[i] == 'G')
		{
			s++;
		}
		else
		{
			s--;
		}
		if (p[s] == -1)
		{
			p[s] = i + 1;
		}
		else
		{
			z = max(z, i + 1 - p[s]);
		}
	}
	printf("%d\n", z);
	return 0;
}