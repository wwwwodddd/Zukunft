#include <bits/stdc++.h>
using namespace std;
long long n, z;
int main()
{
	cin >> n;
	for (long long i = 1, j; i <= n; i = j + 1)
	{
		j = n / (n / i);
		z += (j - i + 1) * (n / i);
	}
	cout << z << endl;
	return 0;
}
