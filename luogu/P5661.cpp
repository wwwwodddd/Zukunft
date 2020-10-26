#include <bits/stdc++.h>
using namespace std;
int n, b, f, x, y, z, s;
int t[100020];
int p[100020];
bool v[100020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		s += y;
		if (x)
		{
			while (b < f && t[b] < z)
			{
				b++;
			}
			for (int j = b; j < f; j++)
			{
				if (p[j] >= y && !v[j])
				{
					v[j] = true;
					s -= y;
					break;
				}
			}
		}
		else
		{
			t[f] = z + 45;
			p[f] = y;
			f++;
		}
	}
	printf("%d\n", s);
	return 0;
}