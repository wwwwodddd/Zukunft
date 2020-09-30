#include <bits/stdc++.h>
using namespace std;
int n, v[10020];
int main()
{
	for (int i = 2; i < 10010; i++)
	{
		if (!v[i])
		{
			for (int j = i; j < 10010; j += i)
			{
				v[j] = i;
			}
		}
	}
	cin >> n;
	for (int i = 4; i <= n; i += 2)
	{
		for (int j = 2; j < i; j++)
		{
			if (v[j] == j && v[i - j] == i - j)
			{
				printf("%d=%d+%d\n", i, j, i - j);
				break;
			}
		}
	}
	return 0;
}