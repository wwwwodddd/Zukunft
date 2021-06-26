#include <bits/stdc++.h>
using namespace std;
int a[17], z;
int main()
{
	for (int i = 0; i < 8; i++)
	{
		cin >> a[i];
		a[i + 8] = a[i];
	}
	for (int i = 0; i < 8; i++)
	{
		z = max(z, a[i] + a[i + 1] + a[i + 2] + a[i + 3]);
	}
	cout << z << endl;
	return 0;
}