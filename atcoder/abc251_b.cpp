#include <bits/stdc++.h>
using namespace std;
int n, w, z;
int a[300];
int v[3000020];
int main()
{
	cin >> n >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		v[a[i]] = 1;
		for (int j = 0; j < i; j++)
		{
			v[a[i] + a[j]] = 1;
			for (int k = 0; k < j; k++)
			{
				v[a[i] + a[j] + a[k]] = 1;
			}
		}
	}
	for (int i = 1; i <= w; i++)
	{
		z += v[i];
	}
	cout << z << endl;
	return 0;
}
