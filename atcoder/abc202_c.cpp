#include <bits/stdc++.h>
using namespace std;
int n, x;
int b[100020];
int g[100020];
long long z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		g[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		z += g[b[x]];
	}
	cout << z << endl;
	return 0;
}
