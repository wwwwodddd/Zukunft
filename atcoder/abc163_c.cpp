#include <bits/stdc++.h>
using namespace std;
int n, x, c[200020];
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		c[x]++;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << c[i] << endl;
	}
	return 0;
}
