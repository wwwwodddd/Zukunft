#include <bits/stdc++.h>
using namespace std;
char s[100020];
int read(int p)
{
	scanf("%s", s);
	int r = 0;
	for (int i = 0; s[i]; i++)
	{
		r = r * 10 + s[i] - '0';
		if (r >= p)
		{
			r = r % p + p;
		}
	}
	return r;
}
int main()
{
	int b = read(9);
	int e = read(6);
	int z = 1;
	for (int i = 0; i < e; i++)
	{
		z = z * b % 9;
	}
	printf("%d\n", z ? z : 9);
	return 0;
}