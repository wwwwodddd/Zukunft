#include <bits/stdc++.h>
using namespace std;
set<int> c;
int n, k, x, z;
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		c.insert(x);
		if (c.find(x - k) != c.end() || c.find(x + k) != c.end())
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}