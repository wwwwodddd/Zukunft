#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	if (n & 1)
	{
		cout << -1 << endl;
	}
	else
	{
		for (int i = 30; i > 0; i--)
		{
			if (n >> i & 1)
			{
				cout << (1 << i) << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}