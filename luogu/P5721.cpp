#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	for (int i = n, k = 0; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			printf("%02d", ++k);
		}
		printf("\n");
	}
	return 0;
}