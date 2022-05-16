#include <bits/stdc++.h>
using namespace std;
int t;
char s[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%s", s);
		long long x = 0, y = 0, z = 0;
		for (int i = 0; s[i]; i++)
		{
			if (s[i] == 's')
			{
				x += 1;
				z += y;
			}
			else if (s[i] == 'm')
			{
				y += x;
			}
		}
		printf("%lld\n", z);
	}
	return 0;
}