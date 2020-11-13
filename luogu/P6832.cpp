#include <bits/stdc++.h>
using namespace std;
char s[10000020];
int c[256], z;
int main()
{
	scanf("%s", s);
	for (int i = 0; s[i]; i++)
	{
		z = max(z, ++c[s[i]]);
	}
	printf("%d\n", z);
	return 0;
}