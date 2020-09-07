#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[50020];
int ql[50020], bl, fl;
int qr[50020], br, fr;
int n, d, z;
int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	for (int i = 0, jl = 0, jr = 0; i < n; i++)
	{
		while (jl < n && a[jl].first <= a[i].first)
		{
			while (bl < fl && a[ql[fl - 1]].second <= a[jl].second)
			{
				fl--;
			}
			ql[fl++] = jl++;
		}
		while (jr < n && a[jr].first <= a[i].first + d)
		{
			while (br < fr && a[qr[fr - 1]].second <= a[jr].second)
			{
				fr--;
			}
			qr[fr++] = jr++;
		}
		while (a[ql[bl]].first < a[i].first - d)
		{
			bl++;
		}
		while (a[qr[br]].first < a[i].first)
		{
			br++;
		}
		if (min(a[qr[br]].second, a[ql[bl]].second) >= a[i].second * 2)
		{
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}