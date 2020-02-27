#include <bits/stdc++.h>
using namespace std;
int n, q, l, x;
vector<int> a[100020]; // a[i] i出现的位置
int main()
{
	scanf("%*d%d%d%*d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		a[x].push_back(i);
	}
	for (int i = 0; i < q; i++)
	{
		int p = 0;
		scanf("%d", &l);
		bool found = true;
		for (int j = 0; j < l; j++)
		{
			scanf("%d", &x);
			// 找是x的位置中，最小的>p的，
			auto it = upper_bound(a[x].begin(), a[x].end(), p);
			if (it == a[x].end())
			{
				found = false;
			}
			else
			{
				p = *it;
			}
		}
		puts(found ? "Yes" : "No");
	}
	return 0;
}