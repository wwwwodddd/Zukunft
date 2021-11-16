#include <bits/stdc++.h>
using namespace std;
int n, s, d, x, y;
int main()
{
	cin >> n >> s >> d;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (x < s && y > d)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
