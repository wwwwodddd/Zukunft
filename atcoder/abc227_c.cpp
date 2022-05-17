#include <bits/stdc++.h>
using namespace std;
long long n, z;
int main()
{
	cin >> n;
	for (long long a = 1; a * a * a <= n; a++)
	{
		for (long long b = a; a * b * b <= n; b++)
		{
			z += n / a / b - b + 1;
		}
	}
	cout << z << endl;
	return 0;
}
