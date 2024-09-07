#include <bits/stdc++.h>
using namespace std;
vector<int> a[3];
int main()
{
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 3; i++)
		{
			a[i].resize(n);
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &a[i][j]);
			}
			a[i].push_back(i);
		}
		long long tot = 0;
		for (int i = 0; i < n; i++)
		{
			tot += a[0][i];
		}
		sort(a, a + 3);
		vector<int> ok;
		do
		{
			int p = 0, i = 0;
			long long t = 0;
			ok.resize(6);
			ok[a[0].back() * 2] = 1;
			while (i < 3 && p < n)
			{
				t += a[i][p++];
				if (t * 3 >= tot)
				{
					ok[a[i].back() * 2 + 1] = (i < 2 ? p : n);
					i++;
					if (i < 3)
					{
						ok[a[i].back() * 2] = p + 1;
					}
					t = 0;
				}
			}
			if (i == 3)
			{
				break;
			}
			ok.clear();
		}
		while (next_permutation(a, a + 3));
		if (ok.size() == 0)
		{
			puts("-1");
		}
		else
		{
			for (int i = 0; i < 6; i++)
			{
				printf("%d%c", ok[i], i < 5 ? ' ' : '\n');
			}
		}
	}
	return 0;
}