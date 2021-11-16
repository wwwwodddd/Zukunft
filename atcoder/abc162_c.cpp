#include <bits/stdc++.h>
using namespace std;
int k, z;
int main()
{
	cin >> k;
	for (int a = 1; a <= k; a++)
	{
		for (int b = 1; b <= k; b++)
		{
			for (int c = 1; c <= k; c++)
			{
				z += __gcd(a, __gcd(b, c));
			}
		}
	}
	cout << z << endl;
	return 0;
}
