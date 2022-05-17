#include <bits/stdc++.h>
using namespace std;
int n, x, a[9], v[9];
int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
	}
	cin >> n;
	for (int k = 0; k < n; k++)
	{
		cin >> x;
		for (int i = 0; i < 9; i++)
		{
			if (a[i] == x)
			{
				v[i] = 1;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (v[i * 3 + 0] && v[i * 3 + 1] && v[i * 3 + 2])
		{
			cout << "Yes" << endl;
			return 0;
		}
		if (v[i + 3 * 0] && v[i + 3 * 1] && v[i + 3 * 2])
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	if (v[0] && v[4] && v[8] || v[2] && v[4] && v[6])
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;	
	}
	return 0;
}
