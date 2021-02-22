#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%*d%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j > 0; j /= 10)
		{
			putchar('a' + j % 10);
		}
		putchar(i == n ? '\n' : ' ');
	}
	return 0;
}