#include<bits/stdc++.h>
using namespace std;
int c[601];
int n, w, x;
int main()
{
	scanf("%d%d", &n, &w);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		c[x]++;
		int s = max(1, i * w / 100);
		for (int j = 600;; j--)
		{
			if (s > c[j])
			{
				s -= c[j];
			}
			else
			{
				printf("%d ", j);
				break;
			}
		}
	}
	printf("\n");
	return 0;
}