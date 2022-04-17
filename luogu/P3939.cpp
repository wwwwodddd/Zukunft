#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[300020];
vector<int> b[300020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[a[i]].push_back(i);
	}
	for (int i = 0; i < m; i++)
	{
		int o, l, r, c, x;
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d%d%d", &l, &r, &c);
			printf("%d\n", int(upper_bound(b[c].begin(), b[c].end(), r) - lower_bound(b[c].begin(), b[c].end(), l)));
		}
		else
		{
			scanf("%d", &x);
			*lower_bound(b[a[x]].begin(), b[a[x]].end(), x) += 1;
			swap(a[x], a[x + 1]);
			*lower_bound(b[a[x]].begin(), b[a[x]].end(), x) -= 1;
		}
	}
	return 0;
}
