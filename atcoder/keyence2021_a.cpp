#include <bits/stdc++.h>
using namespace std;
int n;
int a[200020];
long long b, c;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] = max(a[i], a[i - 1]);
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b;
		c = max(c, a[i] * b);
		cout << c << endl;
	}
	return 0;
}
