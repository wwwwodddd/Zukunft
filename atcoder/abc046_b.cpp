#include <bits/stdc++.h>
using namespace std;
int n, k, z;
int main()
{
	cin >> n >> k;
	z = k;
	for (int i = 1; i < n; i++)
	{
		z *= k - 1;
	}
	cout << z << endl;
	return 0;
}
