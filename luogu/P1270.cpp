#include <bits/stdc++.h>
using namespace std;
vector<int> gao(int t)
{
	vector<int> f(t + 1);
	int x, y;
	scanf("%d%d", &x, &y);
	if (y)
	{
		for (int i = 0; i <= t; i++)
		{
			f[i] = min(max(i - 2 * x, 0) / 5, y);
		}
	}
	else
	{
		vector<int> L = gao(t - 2 * x);
		vector<int> R = gao(t - 2 * x);
		for (int i = 0; i + 2 * x <= t; i++)
		{
			for (int j = 0; i + j + 2 * x <= t; j++)
			{
				f[i + j + 2 * x] = max(f[i + j + 2 * x], L[i] + R[j]);
			}
		}
	}
	return f;
}
int main()
{
	int t;
	scanf("%d", &t);
	printf("%d\n", gao(t - 1).back());
	return 0;
}