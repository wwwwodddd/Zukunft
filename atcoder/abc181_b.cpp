#include <bits/stdc++.h>
using namespace std;
long long n, a, b, z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		z += (a + b) * (b - a + 1) / 2;
	}
	cout << z << endl;
	return 0;
}
