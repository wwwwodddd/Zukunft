#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	for (int i = n; i <= 1000000; i += n)
	{
		printf("%d ", i);
	}
	return 0;
}