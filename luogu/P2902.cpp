#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, c, x;
	scanf("%d%d", &n, &c);
	vector<int> a;
	a.reserve(n);
	for (int i = 1; i <= c; i++)
	{
		scanf("%d", &x);
		for (int j = 0; j < x; j++)
		{
			a.push_back(i);
		}
	}
	for (int i = 0; i < n / 2; i++)
	{
		printf("%d %d\n", a[i], a[i + n / 2]);
	}
	return 0;
}