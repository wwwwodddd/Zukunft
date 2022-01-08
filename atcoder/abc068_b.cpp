#include <bits/stdc++.h>
using namespace std;
int n, z = 1;
int main()
{
	cin >> n;
	while (z * 2 <= n)
	{
		z *= 2;
	}
	cout << z << endl;
	return 0;
}
