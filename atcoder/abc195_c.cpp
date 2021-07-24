#include <bits/stdc++.h>
using namespace std;
long long n, z;
int main()
{
	cin >> n;
	for (long long i = 1000; i <= n; i *= 1000)
	{
		z += n - i + 1;
	}
	cout << z << endl;
	return 0;
}
