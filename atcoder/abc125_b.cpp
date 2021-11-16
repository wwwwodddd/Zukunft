#include <bits/stdc++.h>
using namespace std;
int n, z;
int c[20], v[20];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		z += max(v[i] - c[i], 0);
	}
	cout << z << endl;
	return 0;
}
