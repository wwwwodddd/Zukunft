#include <bits/stdc++.h>
using namespace std;
int n;
long long s[200020], l, r;
int main()
{
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] += s[i - 1];
	}
	long long z = s[n];
	long long t = 0;
	for (int j = 0; j <= n; j++)
	{
		t = min(t, j * l - s[j]);
		z = min(z, t + (n - j) * r + s[j]);
	}
	cout << z << endl;
	return 0;
}
