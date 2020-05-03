#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int v[10020];
long long f[10020];
int main()
{
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		f[i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		if (!v[i])
		{
			for (int j = n; j > 0; j--)
			{
				for (int k = i; k <= j; k *= i)
				{
					f[j] += f[j - k];
				}
			}
			for (int j = i; j <= n; j += i)
			{
				v[j] = i;
			}
		}
	}
	printf("%lld\n", f[n]);
	return 0;
}