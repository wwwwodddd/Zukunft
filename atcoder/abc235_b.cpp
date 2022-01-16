#include <bits/stdc++.h>
using namespace std;
int n, x, l;
int main()
{
	cin >> n >> l;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		if (l >= x)
		{
			break;
		}
		l = x;
	}
	cout << l << endl;
	return 0;
}
