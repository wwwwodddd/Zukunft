#include <bits/stdc++.h>
using namespace std;
int n, m, s, c;
int a[100];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (4 * m * a[i] >= s)
		{
			c++;
		}
	}
	cout << (c < m ? "No" : "Yes") << endl;
	return 0;
}
