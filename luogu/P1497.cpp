#include <bits/stdc++.h>
using namespace std;
int n, k, h, x;
long long z = 1;
int main()
{
	cin >> n >> k >> h;
	for (int i = 0; i < k; i++)
	{
		z *= (n - i) * (n - i);
	}
	for (int i = 0; i < h; i++)
	{
		cin >> x;
		for (int j = 1; j <= x; j++)
		{
			z /= j;
		}
	}
	cout << z << endl;
	return 0;
}