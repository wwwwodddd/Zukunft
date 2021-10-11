#include <bits/stdc++.h>
using namespace std;
int n, a[100], z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (a[i] != a[j] && a[j] != a[k] && a[k] + a[j] > a[i])
				{
					z++;
				}
			}
		}
	}
	cout << z << endl;
	return 0;
}
