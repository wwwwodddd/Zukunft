#include <bits/stdc++.h>
using namespace std;
map<long long, long long> f;
long long n;
long long F(long long k)
{
	if (f.find(k) == f.end())
	{
		f[k] = F(k / 2) + F(k / 3);
	}
	return f[k];
}
int main()
{
	f[0] = 1;
	cin >> n;
	cout << F(n) << endl;
	return 0;
}