#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int vv[200020], *v = vv + 100010;
int dd[200020], *d = dd + 100010;
char s[200020];
int ff[5], *f = ff + 2;
int z;
void L1()
{
	int p = 0, c = 0;
	memset(dd, 0, sizeof dd);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L')
		{
			p--;
		}
		else if (s[i] == 'R')
		{
			p++;
		}
		else if (s[i] == 'F')
		{
			if (v[p])
			{
				c += !d[p]++;
			}
		}
	}
	z = max(z, c);
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == 'L')
		{
			p++;
		}
		else if (s[i] == 'R')
		{
			p--;
			z = max(z, c + (v[p] && d[p] == 0));
		}
		else if (s[i] == 'F')
		{
			if (v[p])
			{
				c -= !--d[p];
			}
			z = max(z, c);
			if (v[p - 1])
			{
				c += !d[p - 1]++;
			}
		}
	}
}
void R1()
{
	int p = 0, c = 0;
	memset(dd, 0, sizeof dd);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L')
		{
			p--;
		}
		else if (s[i] == 'R')
		{
			p++;
		}
		else if (s[i] == 'F')
		{
			if (v[p])
			{
				c += !d[p]++;
			}
		}
	}
	z = max(z, c);
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == 'L')
		{
			p++;
			z = max(z, c + (v[p] && d[p] == 0));
		}
		else if (s[i] == 'R')
		{
			p--;
		}
		else if (s[i] == 'F')
		{
			if (v[p])
			{
				c -= !--d[p];
			}
			z = max(z, c);
			if (v[p + 1])
			{
				c += !d[p + 1]++;
			}
		}
	}
}
void L2()
{
	int p = 0, c = 0;
	memset(dd, 0, sizeof dd);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L')
		{
			p--;
		}
		else if (s[i] == 'R')
		{
			p++;
		}
		else if (s[i] == 'F')
		{
			if (v[p])
			{
				c += !d[p]++;
			}
		}
	}
	z = max(z, c);
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == 'L')
		{
			p++;
		}
		else if (s[i] == 'R')
		{
			p--;
			z = max(z, c);
		}
		else if (s[i] == 'F')
		{
			if (v[p])
			{
				c -= !--d[p];
			}
			if (v[p - 2])
			{
				c += !d[p - 2]++;
			}
		}
	}
}
void R2()
{
	int p = 0, c = 0;
	memset(dd, 0, sizeof dd);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L')
		{
			p--;
		}
		else if (s[i] == 'R')
		{
			p++;
		}
		else if (s[i] == 'F')
		{
			if (v[p])
			{
				c += !d[p]++;
			}
		}
	}
	z = max(z, c);
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == 'L')
		{
			p++;
			z = max(z, c);
		}
		else if (s[i] == 'R')
		{
			p--;
		}
		else if (s[i] == 'F')
		{
			if (v[p])
			{
				c -= !--d[p];
			}
			if (v[p + 2])
			{
				c += !d[p + 2]++;
			}
		}
	}
}
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &x);
		v[x] = 1;
	}
	scanf("%s", s);
	L1();
	R1();
	L2();
	R2();
	printf("%d\n", z);
	return 0;
}