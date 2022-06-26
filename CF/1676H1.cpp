#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int z = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			for (int j = 0; j < i; j++)
			{
				if (a[j] >= a[i])
				{
					z++;
				}
			}
		}
		cout << z << endl;
	}
	return 0;
}
