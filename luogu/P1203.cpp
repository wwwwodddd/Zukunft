#include <bits/stdc++.h>
using namespace std;
int n, a, b, w, z;
char s[400], c;
int main()
{
	scanf("%d%s", &n, s);
	for (int i = 0; i < 2 * n; i++)
	{
		if (s[i % n] == 'w')
		{
			b++;
			w++;
		}
		else if (s[i % n] == c)
		{
			b++;
			w = 0;
		}
		else
		{
			z = max(z, a + b);
			a = b - w;
			b = w + 1;
			w = 0;
			c = s[i % n];
		}
	}
	z = max(z, a + b);
	printf("%d\n", min(z, n));
	return 0;
}