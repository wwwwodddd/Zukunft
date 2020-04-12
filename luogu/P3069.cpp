#include <bits/stdc++.h>
using namespace std;
map<int, int> c;
int n, m, z, cnt;
int a[100020];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0, j = 0; j < n; j++)
	{
		scanf("%d", &a[j]);
		cnt += !c[a[j]]++;
		while (cnt > m + 1)
		{
			cnt -= !--c[a[i++]];
		}
		z = max(z, c[a[j]]);
	}
	printf("%d\n", z);
	return 0;
}