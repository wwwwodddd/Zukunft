#include <bits/stdc++.h>
using namespace std;
int n, c, z;
int a[10];
int main()
{
	cin >> n;
	while (n > 0)
	{
		a[c++] = n % 10;
		n /= 10;
	}
	sort(a, a + c);
	do
	{
		for (int i = 1; i < c; i++)
		{
			int x = 0, y = 0;
			for (int j = 0; j < i; j++)
			{
				x = x * 10 + a[j];
			}
			for (int j = i; j < c; j++)
			{
				y = y * 10 + a[j];
			}
			z = max(z, x * y);
		}
	}
	while (next_permutation(a, a + c));
	cout << z << endl;
	return 0;
}
