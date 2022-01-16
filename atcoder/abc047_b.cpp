#include <bits/stdc++.h>
using namespace std;
int w, h, n, x, y, a;
int xmn, ymn, xmx, ymx;
int main()
{
	cin >> w >> h >> n;
	xmn = w;
	ymn = h;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> a;
		if (a == 1)
		{
			xmx = max(xmx, x);
		}
		else if (a == 2)
		{
			xmn = min(xmn, x);
		}
		else if (a == 3)
		{
			ymx = max(ymx, y);
		}
		else if (a == 4)
		{
			ymn = min(ymn, y);
		}
	}
	cout << max(ymn - ymx, 0) * max(xmn - xmx, 0) << endl;
	return 0;
}
