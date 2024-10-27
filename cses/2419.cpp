#include <bits/stdc++.h>
using namespace std;
int n, s, x;
int main()
{
	cin >> n;
	n--;
	for (int i = 0; i <= n; i++)
	{
		cin >> x;
		if ((n & i) == i)
		{
			s ^= x;
		}
	}
	cout << s << endl;
	return 0;
}