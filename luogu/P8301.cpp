#include <bits/stdc++.h>
using namespace std;
int n, z;
string a, b;
int main()
{
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
	{
		z += a[i] - b[i];
	}
	cout << abs(z) << endl;
	return 0;
}
