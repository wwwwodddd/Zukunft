#include <bits/stdc++.h>
using namespace std;
char c[300];
char s[300];
int k, n, i;
int main()
{
	scanf("%s%d", c, &k);
	for (int i = 0; c[i]; i++)
	{
		while (k > 0 && n > 0 && s[n-1] > c[i])
		{
			k--;
			n--;
		}
		s[n++] = c[i];
	}
	n -= k;
	s[n] = 0;
	while (i < n - 1 && s[i] == '0')
	{
		i++;
	}
	printf("%s\n", s + i);
	return 0;
}