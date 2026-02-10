#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int s[1000020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		s[x]++;
		s[y + 1]--;
	}
	int z = 0;
	for (int i = 0; i <= 1000000; i++)
	{
		s[i + 1] += s[i];
		z = max(z, s[i]);
	}
	printf("%d\n", z);
	return 0;
}