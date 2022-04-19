#include <bits/stdc++.h>
using namespace std;
int k, a;
int main()
{
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		a = (10 * a + 7) % k;
		if (a == 0)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
