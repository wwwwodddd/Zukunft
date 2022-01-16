#include <bits/stdc++.h>
using namespace std;
int n, x, l;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (l < x)
		{
			l = x - 1;
		}
		else if (l > x)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
