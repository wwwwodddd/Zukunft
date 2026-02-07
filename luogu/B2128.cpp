#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n, c = 0;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if (isPrime(i))
		{
			c++;
		}
	}
	cout << c << endl;
	return 0;
}