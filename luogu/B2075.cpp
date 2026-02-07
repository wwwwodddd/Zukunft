#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, z = 1;
	scanf("%d%d", &a, &b);
	for (int i = 0; i < b; i++)
	{
		z = z * a % 1000;
	}
	printf("%03d\n", z);
	return 0;
}