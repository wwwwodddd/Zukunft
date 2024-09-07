#include <bits/stdc++.h>
using namespace std;
int n;
int h[100020];
int f[100020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	f[1] = 0;
	f[2] = abs(h[1] - h[2]);
	for (int i = 3; i <= n; i++)
	{
		f[i] = min(f[i - 1] + abs(h[i] - h[i - 1]), f[i - 2] + abs(h[i] - h[i - 2]));
	}
	cout << f[n] << endl;
	return 0;
}