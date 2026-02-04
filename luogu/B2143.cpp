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
	printf("%X", z % m);
}
int main()
{
	scanf("%d%d", &n, &m);
	print(n);
	return 0;
}