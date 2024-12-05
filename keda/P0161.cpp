#include <bits/stdc++.h>
using namespace std;
int y, m;
int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
	scanf("%d%d", &y, &m);
	if (y % 400 == 0 || y % 100 != 0 && y % 4 == 0)
	{
		d[2]++;
	}
	printf("%d\n", d[m]);
	return 0;
}