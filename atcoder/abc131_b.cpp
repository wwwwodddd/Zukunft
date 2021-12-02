#include <bits/stdc++.h>
using namespace std;
int n, l;
int main()
{
	cin >> n >> l;
	int s = (l + l + n - 1) * n / 2;
	if (l > 0)
	{
		cout << s - l << endl;
	}
	else if (l + n - 1 < 0)
	{
		cout << s - (l + n - 1) << endl;
	}
	else
	{
		cout << s << endl;
	}
	return 0;
}
