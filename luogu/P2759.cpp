#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
	cin >> n;
	long long L = 0;
	long long R = n;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		if ((long long)(log10(M) * M) + 1 >= n)
		{
			R = M;
		}
		else
		{
			L = M;
		}
	}
	cout << R << endl;
	return 0;
}
