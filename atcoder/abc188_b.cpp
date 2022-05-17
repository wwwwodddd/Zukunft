#include <bits/stdc++.h>
using namespace std;
int n, s;
int a[100020];
int b[100020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		s += a[i] * b[i];
	}
	cout << (s ? "No" : "Yes") << endl;
	return 0;
}
