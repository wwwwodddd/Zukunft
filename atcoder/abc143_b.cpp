#include <bits/stdc++.h>
using namespace std;
int n, x, s, t;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += x;
		t += x * x;
	}
	cout << (s * s - t) / 2 << endl;
	return 0;
}
