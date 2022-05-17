#include <bits/stdc++.h>
using namespace std;
int n, z;
int main()
{
	cin >> n;
	for (int a = 1; a <= n; a++)
	{
		z += (n - 1) / a;
	}
	cout << z << endl;
	return 0;
}
