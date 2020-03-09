#include <bits/stdc++.h>
using namespace std;
char a[10020];
char b[10020];
int f[10020];
int main()
{
	scanf("%s%s", a + 1, b + 1);
	int la = strlen(a + 1);
	int lb = strlen(b + 1);
	for (int i = 1; i <= la; i++)
	{
		for (int j = lb; j >= 1; j--)
		{
			if (a[i] == b[j])
			{
				f[j] = max(f[j], f[j - 1] + 1);
			}
		}
		for (int j = 1; j <= lb; j++)
		{
			f[j] = max(f[j], f[j - 1]);
		}
	}
	printf("%d\n", f[lb]);
	return 0;
}