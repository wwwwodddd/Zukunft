#include <bits/stdc++.h>
int n;
int main()
{
	while (scanf("%d", &n), n)
	{
		puts(n & 1 ? "Bob" : "Alice");
	}
	return 0;
}