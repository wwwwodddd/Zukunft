#include <bits/stdc++.h>
using namespace std;
int n;
long long x, s = 1, m = 1e18;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s *= x;
		if (x == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		else
		{
			m /= x;		
		}
	}
	if (m > 0)
	{
		cout << s << endl;
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}
