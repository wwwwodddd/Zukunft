#include <bits/stdc++.h>
using namespace std;
int n, d, s, x;
int main()
{
	cin >> n >> d >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += (d - 1) / x + 1;
	}
	cout << s << endl;
	return 0;
}
