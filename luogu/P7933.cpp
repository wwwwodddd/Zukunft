#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			cout << n - n / i << endl;
			return 0;
		}
	}
	cout << n - 1 << endl;
	return 0;
}
