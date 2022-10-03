#include <bits/stdc++.h>
using namespace std;
int t, n, x, l;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		vector<int> f{-1};
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (x > f.back())
			{
				f.push_back(x);
			}
			else
			{
				*lower_bound(f.begin(), f.end(), x) = x;
			}
		}
		scanf("%d", &l);
		printf("%d\n", l < f.size() ? f[l] : -1);
	}
	return 0;
}