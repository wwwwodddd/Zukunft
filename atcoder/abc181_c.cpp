#include <bits/stdc++.h>
using namespace std;
int n, x[100], y[100];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				if ((x[j] - x[i]) * (y[k] - y[i]) - (x[k] - x[i]) * (y[j] - y[i]) == 0)
				{
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
