#include <bits/stdc++.h>
using namespace std;
int q, x, y;
bitset<20001> b[20001];
char o;
int main()
{
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf(" %c%d%d", &o, &x, &y);
		if (o == '+')
		{
			b[x][y] = 1;
		}
		else if (o == '-')
		{
			b[x][y] = 0;
		}
		else if (o == 'v')
		{
			printf("%lu\n", (b[x] | b[y]).count());
		}
		else if (o == '^')
		{
			printf("%lu\n", (b[x] & b[y]).count());
		}
		else if (o == '!')
		{
			printf("%lu\n", (b[x] ^ b[y]).count());
		}
		else
		{
			printf("%lu\n", (b[x] & ~b[y]).count());
		}
	}
	return 0;
}