#include <bits/stdc++.h>
using namespace std;
int P(int x)
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
	int n;
	cin >> n;
	while (!P(n))
	{
		n++;
	}
	cout << n << endl;
	return 0;
}
