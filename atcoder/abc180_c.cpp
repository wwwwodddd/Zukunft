#include <bits/stdc++.h>
using namespace std;
vector<long long> d;
long long n;
int main()
{
	cin >> n;
	for (long long i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			d.push_back(i);
			if (i * i < n)
			{
				d.push_back(n / i);
			}
		}
	}
	sort(d.begin(), d.end());
	for (long long i: d)
	{
		cout << i << endl;
	}
}
