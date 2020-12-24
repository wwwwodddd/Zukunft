#include <bits/stdc++.h>
using namespace std;
string k, c;
int main()
{
	cin >> k >> c;
	for (int i = 0; i < c.size(); i++)
	{
		int t = k[i % k.size()] % 32 - 1;
		c[i] = c[i] % 32 - t > 0 ? c[i] - t : c[i] - t + 26;
	}
	cout << c << endl;
	return 0;
}