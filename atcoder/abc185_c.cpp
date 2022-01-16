#include <bits/stdc++.h>
using namespace std;
long long n, z = 1;
int main()
{
	cin >> n;
	for (int i = 1; i <= 11; i++)
	{
		z = z * (n - i) / i;
	}
	cout << z << endl;
	return 0;
}
