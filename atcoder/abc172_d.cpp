#include <bits/stdc++.h>
using namespace std;
long long n, z;
int main()
{
	cin >> n;
	for (int j = 1; j <= n; j++)
	{
		z += (j + n / j * j) * (n / j) / 2;
	}
	cout << z << endl;
	return 0;
}
