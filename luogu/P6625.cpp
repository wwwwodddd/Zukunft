#include <bits/stdc++.h>
using namespace std;
long long n, s, x, z;
int main()
{
	cin >> n >> s;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		s += x;
		z += max(s, 0LL);
	}
	cout << z << endl;
	return 0;
}