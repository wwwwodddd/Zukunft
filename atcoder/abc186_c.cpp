#include <bits/stdc++.h>
using namespace std;
bool dec(int n)
{
	for (;n > 0; n /= 10)
	{
		if (n % 10 == 7)
		{
			return false;
		}
	}
	return true;
}
bool oct(int n)
{
	for (;n > 0; n /= 8)
	{
		if (n % 8 == 7)
		{
			return false;
		}
	}
	return true;
}
int n, z;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (dec(i) && oct(i))
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
