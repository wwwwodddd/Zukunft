#include <bits/stdc++.h>
using namespace std;
int n, z = 1;
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		for (int j = i * i; j <= n; j *= i)
		{
			z = max(z, j);
		}
	}
	cout << z << endl;
	return 0;
}
