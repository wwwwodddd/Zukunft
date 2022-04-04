#include <bits/stdc++.h>
using namespace std;
int x, c[5];
int main()
{
	for (int i = 0; i < 6; i++)
	{
		cin >> x;
		c[x]++;
		if (c[x] == 3)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
