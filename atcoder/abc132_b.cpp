#include <bits/stdc++.h>
using namespace std;
int n, a[20], z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i + 1 < n; i++)
	{
		if (a[i - 1] < a[i] && a[i] < a[i + 1] || a[i - 1] > a[i] && a[i] > a[i + 1])
		{
			z++;
		}
	}
	cout << z << endl;
	return 0;
}
