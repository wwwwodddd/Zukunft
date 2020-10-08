#include <bits/stdc++.h>
using namespace std;
int n, z;
int a[1020];
int b[1020];
int c[1020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (abs(a[i] - a[j]) <= 5 && abs(b[i] - b[j]) <= 5 && abs(c[i] - c[j]) <= 5 && abs(a[i] + b[i] + c[i] - a[j] - b[j] - c[j]) <= 10)
			{
				z++;
			}
		}
	}
	printf("%d\n", z);
	return 0;
}