#include <bits/stdc++.h>
using namespace std;
int n, l, x;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		cout << x - l << " ";
		l = x;
	}
	return 0;
}
