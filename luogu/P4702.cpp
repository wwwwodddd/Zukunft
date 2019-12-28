#include <bits/stdc++.h>
using namespace std;
int n, x;
long long s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += x;
	}
	cout << (s & 1 ? "Alice" : "Bob") << endl;
	return 0;
}