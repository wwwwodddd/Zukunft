#include <bits/stdc++.h>
using namespace std;
int n, z = -1;
int main()
{
	cin >> n;
	for (int i = 0; i < 5 && 3 * i <= n; i++)
	{
		if ((n - 3 * i) % 5 == 0)
		{
			z = i + (n - 3 * i) / 5;
		}
	}
	cout << z << endl;
	return 0;
}
