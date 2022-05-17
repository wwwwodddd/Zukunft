#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
int main()
{
	cin >> n;
	for (long long i = 2; i * i <= n; i++)
	{
		for (long long j = i * i; j <= n; j *= i)
		{
			a.push_back(j);
		}
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	cout << n - a.size() << endl;
	return 0;
}
