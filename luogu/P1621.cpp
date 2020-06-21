#include <bits/stdc++.h>
using namespace std;
int a, b, p, z;
int f[100020];
int v[100020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	scanf("%d%d%d", &a, &b, &p);
	for (int i = a; i <= b; i++)
	{
		f[i] = i;
	}
	for (int i = 2; i <= b; i++)
	{
		if (!v[i])
		{
			for (int j = i; j <= b; j += i)
			{
				v[j] = i;
				if (i >= p && j - i >= a)
				{
					if (F(j) != F(j - i))
					{
						z++;
						f[F(j)] = F(j - i);
					}
				}
			}
		}
	}
	printf("%d\n", b - a + 1 - z);
	return 0;
}