#include <bits/stdc++.h>
using namespace std;
int n, x;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		puts(x & 1 ? "zs wins" : "pb wins");
	}
	return 0;
}