#include <bits/stdc++.h>
using namespace std;
long long n, m;
int main()
{
	cin >> n >> m;
	if (n == 1 || m == 1)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << (n * m + 1) / 2 << endl;
	}
	return 0;
}
