#include <bits/stdc++.h>
using namespace std;
long long l, r, w;
int c;
int main()
{
	cin >> l >> r >> w;
	for (long long t = 1;;)
	{
		if (t >= l)
		{
			c++;
			cout << t << ' ';
		}
		if (w > 1 && t <= r / w)
		{
			t *= w;
		}
		else
		{
			break;
		}
	}
	if (c == 0)
	{
		cout << -1;
	}
	cout << endl;
	return 0;
}