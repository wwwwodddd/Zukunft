#include <bits/stdc++.h>
using namespace std;
int n;
int b[120];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		b[i] *= i;
	}
	for (int i = n; i > 0; i--)
	{
		b[i] -= b[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{
		cout << b[i] << ' ';
	}
	return 0;
}