#include <bits/stdc++.h>
using namespace std;
long long n, x, a, b, z;
int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a + b > x)
		{
			z += a + b - x;
			a = x - b;
		}
		b = a;
	}
	cout << z << endl;
	return 0;
}