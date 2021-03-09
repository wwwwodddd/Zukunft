#include <bits/stdc++.h>
using namespace std;
int t, n;
bool f[1000020];
int main()
{
	for (int i = 1; i < 1000010; i++)
	{
		int j = i, mn = 10, mx = 0;
		for (; j > 0; j /= 10)
		{
			if (mx < j % 10)
			{
				mx = j % 10;
			}
			if (mn > j % 10 && j % 10 > 0)
			{
				mn = j % 10;
			}
		}
		f[i] = !f[i - mn] || !f[i - mx];
	}
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		puts(f[n] ? "YES" : "NO");
	}
	return 0;
}