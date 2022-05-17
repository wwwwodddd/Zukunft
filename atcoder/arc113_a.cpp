#include <bits/stdc++.h>
using namespace std;
int k, z;
int main()
{
	cin >> k;
	for (int a = 1; a <= k; a++)
	{
		for (int b = 1; a * b <= k; b++)
		{
			z += k / a / b;
		}
	}
	cout << z << endl;
	return 0;
}