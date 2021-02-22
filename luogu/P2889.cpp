#include <bits/stdc++.h>
using namespace std;
int n, m, r, z;
int f[1020];
int s[1020];
int e[1020];
int w[1020];
int main()
{
	scanf("%d%d%d", &n, &m, &r);
	vector<int> o;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &s[i], &e[i], &w[i]);
		e[i] += r;
		o.push_back(i);
	}
	sort(o.begin(), o.end(), [](int x, int y){return s[x] < s[y];});
	for (int i: o)
	{
		for (int j: o)
		{
			if (s[i] >= e[j])
			{
				f[i] = max(f[i], f[j]);
			}
		}
		f[i] += w[i];
		z = max(z, f[i]);
	}
	printf("%d\n", z);
	return 0;
}