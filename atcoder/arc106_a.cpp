#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
	cin >> n;
	for (long long i = 1, p = 3; p < n; i++, p *= 3)
	{
		for (long long j = 1, q = 5; q < n; j++, q *= 5)
		{
			if (p + q == n)
			{
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
