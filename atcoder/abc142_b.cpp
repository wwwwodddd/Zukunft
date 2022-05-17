#include <bits/stdc++.h>
using namespace std;
int n, k, h, z;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> h;
		if (h >= k)
		{
			z++;
		}
	}
	cout << z << endl;
}
