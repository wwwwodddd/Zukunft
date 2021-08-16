#include <bits/stdc++.h>
using namespace std;
int n, x, f;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x % 2 == 0 && x % 3 != 0 && x % 5 != 0)
		{
			f = 1;
		}
	}
	cout << (f ? "DENIED" : "APPROVED") << endl;
	return 0;
}
