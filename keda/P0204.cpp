#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			cout << n / i << endl;
			break;
		}
	}
	return 0;
}