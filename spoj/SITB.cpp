#include <bits/stdc++.h>
using namespace std;
int n = 10000000;
int p[10000020], pc;
int v[10000020];
int read()
{
	int n=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
	{
		if (c == EOF)
		{
			return EOF;
		}
	}
	for(;isdigit(c);c=getchar())
	{
		n=n*10+c-'0';
	}
	return n;
}
int main()
{
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == 0)
		{
			p[pc++] = i;
			v[i] = i;
		}
		for (int j = 0; j < pc && i * p[j] <= n; j++)
		{
			v[i * p[j]] = p[j];
			if (v[i] == p[j])
			{
				break;
			}
		}
	}
	while ((n = read()) != EOF)
	{
		printf("%d = %d", n, v[n]);
		n /= v[n];
		while (n > 1)
		{
			printf(" x %d", v[n]);
			n /= v[n];
		}
		puts("");
	}
	return 0;
}