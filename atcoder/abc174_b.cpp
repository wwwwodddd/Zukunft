#include <bits/stdc++.h>
using namespace std;
int n, z;
long long x, y, d;
int main()
{
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (x * x + y * y <= d * d)
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
