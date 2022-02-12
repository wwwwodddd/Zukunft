#include <bits/stdc++.h>
using namespace std;
int n, s, x;
int main()
{
	cin >> n;
	for (int i = 1; i < 4 * n; i++)
	{
		cin >> x;
		s ^= x;
	}
	cout << s << endl;
	return 0;
}