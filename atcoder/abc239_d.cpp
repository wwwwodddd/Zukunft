#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
bool isPrime(int x)
{
	if (x < 2)
	{
		return false;
	}
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
	cin >> a >> b >> c >> d;
	for (int i = a; i <= b; i++)
	{
		int f = 0;
		for (int j = c; j <= d; j++)
		{
			if (isPrime(i + j))
			{
				f = 1;
				break;
			}
		}
		if (f == 0)
		{
			cout << "Takahashi" << endl;
			return 0;
		}
	}
	cout << "Aoki" << endl;
	return 0;
}
