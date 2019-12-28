#include <bits/stdc++.h>
using namespace std;
long long calc(long long n)
{
	return n - n / 3 - n / 5 + n / 15;
}
int main()
{
	long long n;
	cin >> n;
	long long L = 0;
	long long R = 2 * n;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		if (calc(M) < n)
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	cout << R << endl;
	return 0;
}