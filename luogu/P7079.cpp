#include <bits/stdc++.h>
using namespace std;
int n, z;
char s[99];
int v[99];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		v[s[0] - 'A'] = 1;
	}
	for (; v[z]; z++)
	{
	}
	printf("%d\n", z);
	return 0;
}