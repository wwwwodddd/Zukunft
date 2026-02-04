#include <bits/stdc++.h>
using namespace std;
int n, m;
void print(int z)
{
	if (z == 0)
	{
		return;
	}
	print(z / m);
	if (z % m < 10)
	{
		printf("%d", z % m);
	}
	else
	{
		printf("%c", z % m + 'A' - 10);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	print(n);
	return 0;
}