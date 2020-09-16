#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 1 << n; i--;)
	{
		for (int j = 1 << n; j--;)
		{
			printf("%d ", !(i&j));
		}
		printf("\n");
	}
	return 0;
}