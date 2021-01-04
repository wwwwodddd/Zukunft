#include <bits/stdc++.h>
using namespace std;
int x, s, z;
int main()
{
	z = -1;
	while (scanf("%1d", &x) != EOF)
	{
		s = max(s, 0) + 1 - 2 * x;
		z = max(z, s);
	}
	printf("%d\n", z);
	return 0;
}