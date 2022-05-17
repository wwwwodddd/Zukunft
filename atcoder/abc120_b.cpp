#include <bits/stdc++.h>
using namespace std;
int a, b, k;
int main()
{
	cin >> a >> b >> k;
	for (int i = 100; i > 0; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			if (--k == 0)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
