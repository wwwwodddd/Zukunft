#include <bits/stdc++.h>
using namespace std;
int n, x;
long long c[200020], z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		c[x]++;
	}
	for (int j = 1; j <= 200000; j++)
	{
		for (int k = 1; j * k <= 200000; k++)
		{
			z += c[j] * c[k] * c[j * k]; 
		}
	}
	cout << z << endl;
	return 0;
}
