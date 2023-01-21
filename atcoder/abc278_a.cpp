#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[233];
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i + k] << " ";
	}
	return 0;
}
