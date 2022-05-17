#include <bits/stdc++.h>
using namespace std;
int n, m, s, p, x;
int t[120];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i]; 
		s += t[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> p >> x;
		cout << s - t[p] + x << endl;
	}
	return 0;
}
