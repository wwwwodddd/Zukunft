#include <bits/stdc++.h>
using namespace std;
int n, m, x, ac, wa;
int c[100020]; 
int v[100020];
string s;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> s;
		if (!v[x])
		{
			if (s == "WA")
			{
				c[x]++;
			}
			else
			{
				v[x] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (v[i])
		{
			ac++;
			wa += c[i];
		}
	}
	cout << ac << " " << wa << endl;
	return 0; 
}
