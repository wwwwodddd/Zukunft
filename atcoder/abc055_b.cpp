#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n;
long long z = 1;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		z = z * i % p;
	}
	cout << z << endl;
	return 0;
}
