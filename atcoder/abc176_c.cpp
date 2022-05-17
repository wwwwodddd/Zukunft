#include <bits/stdc++.h>
using namespace std;
int n, x, a;
long long s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a = max(a, x);
		s += a - x;
	}
	cout << s << endl;
	return 0;
}
