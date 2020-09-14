#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100020];
int n, d;
int q1[100020], b1, f1;
int q2[100020], b2, f2;
int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	int z = 1e9;
	for (int i = 0, j = 0; i < n; i++)
	{
		while (b1 < f1 && q1[b1] < i)
		{
			b1++;
		}
		while (b2 < f2 && q2[b2] < i)
		{
			b2++;
		}
		while (a[q1[b1]].second - a[q2[b2]].second < d && j < n)
		{
			while (b1 < f1 && a[q1[f1 - 1]].second <= a[j].second)
			{
				f1--;
			}
			while (b2 < f2 && a[q2[f2 - 1]].second >= a[j].second)
			{
				f2--;
			}
			q1[f1++] = j;
			q2[f2++] = j++;
		}
		if (a[q1[b1]].second - a[q2[b2]].second >= d)
		{
			z = min(z, a[j-1].first - a[i].first);
		}
	}
	printf("%d\n", z > 1e8 ? -1 : z);
	return 0;
}