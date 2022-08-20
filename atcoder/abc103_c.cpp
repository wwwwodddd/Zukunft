#include <bits/stdc++.h>
using namespace std;
int n, x, z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		z += x - 1;
	}
	cout << z << endl;
	return 0;
}
