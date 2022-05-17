#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		if (n % 200 == 0)
		{
			n /= 200;
		}
		else
		{
			n = n * 1000 + 200;
		}
	}
	cout << n << endl;
	return 0;
}
