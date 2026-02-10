#include <bits/stdc++.h>
using namespace std;
int t, k;
long long n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> k >> n;
		long long b = 0;
		for (int i = 0; i < k; i++)
		{
			b = b * 10 + 9;
		}
		if (n % b == 0)
		{
			cout << "aya" << endl;
		}
		else
		{
			cout << "baka" << endl;
		}
	}
	return 0;
}