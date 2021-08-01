#include <bits/stdc++.h>
using namespace std;
int n, k, z = 1e9, zi;
int a[150020];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
		if (i >= k)
		{
			if (z > a[i] - a[i - k])
			{
				z = a[i] - a[i - k];
				zi = i - k + 1;
			}
		}
	}
	cout << zi << endl;
	return 0;
}