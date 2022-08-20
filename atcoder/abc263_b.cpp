#include <bits/stdc++.h>
using namespace std;
int n;
int d[60];
int p[60];
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		cin >> p[i];
		d[i] = d[p[i]] + 1;
	}
	cout << d[n] << endl;
	return 0;
}
