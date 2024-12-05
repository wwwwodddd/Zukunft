#include <bits/stdc++.h>
using namespace std;
long long s;
int x, n;
int main()
{
	cin >> n;
	while (cin >> x)
	{
		s += x;
	}
	cout << (s << (n - 1)) << endl;
	return 0;
}