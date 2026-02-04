#include <bits/stdc++.h>
using namespace std;
const long long p = 2329089562800;
int l, m;
long long mm[1000020];
int main()
{
	mm[0] = 1;
	mm[1] = 2;
	mm[2] = 4;
	mm[3] = 6;
	for (int i = 4; i <= 1000000; i++)
	{
		mm[i] = (mm[i - 1] + mm[i - 3] + mm[i - 4]) % p;
	}
	while (cin >> l >> m)
	{
		cout << mm[l] % m << endl;
	}
	return 0;
}