#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
	cin >> a >> b;
	for (int i = 0; i < 1111; i++)
	{
		if (i * 2 / 25 == a && i / 10 == b)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
