#include <bits/stdc++.h>
using namespace std;
int n;
int a[2020];
int d[2020];
bool v[2020];
long long ans;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int maxi = -1, maxd = -1;
		for (int j = 0; j < n; j++)
		{
			if (!v[j])
			{
				if (maxd < d[j])
				{
					maxd = d[j];
					maxi = j;
				}
			}
		}
		ans += maxd;
		v[maxi] = true;
		for (int j = 0; j < n; j++)
		{
			if (!v[j])
			{
				d[j] = max(d[j], a[j] ^ a[maxi]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}