#include <bits/stdc++.h>
using namespace std;
int S(int n)
{
	int s = 0;
	while (n > 0)
	{
		n /= 10;
		s++;
	}
	return s;
}
int main()
{
	int n, z = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (S(i) % 2 == 1)
		{
			z++;
		}
	}
	cout << z << endl;
}
