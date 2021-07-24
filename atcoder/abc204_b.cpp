#include <bits/stdc++.h>
using namespace std;
int n, x, s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += max(x - 10, 0);
	}
	cout << s << endl;
	return 0;
}
