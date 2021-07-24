#include <bits/stdc++.h>
using namespace std;
int n, k, z;
int a[300020];
map<int, int> g;
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		g[a[i]]++;
		if (i >= k && !--g[a[i - k]])
		{
			g.erase(a[i - k]);
		}
		z = max(z, int(g.size()));
	}
	cout << z << endl;
	return 0;
}
