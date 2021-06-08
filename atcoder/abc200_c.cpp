#include <bits/stdc++.h>
using namespace std;
int n, x, c[200];
long long z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		z += c[x % 200]++;
	}
	cout << z << endl;
	return 0;
}
