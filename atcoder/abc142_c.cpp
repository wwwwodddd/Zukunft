#include <bits/stdc++.h>
using namespace std;
int a[100020];
int n, x;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		a[x] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
