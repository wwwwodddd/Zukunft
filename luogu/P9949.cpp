#include <bits/stdc++.h>
using namespace std;
int x[120], y[120];
int n, ans;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (x[i] == x[j])
			{
				for (int k = 0; k < n; k++)
				{
					if (y[i] == y[k])
					{
						ans = max(ans, abs((y[i] - y[j]) * (x[i] - x[k])));
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}