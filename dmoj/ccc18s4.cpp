#include <bits/stdc++.h>
using namespace std;
int m;
long long f1[1000020];
long long f2[1000020];
long long F(int n)
{
	long long *t = nullptr;
	if (n < 1000000)
	{
		t = f1 + n;
	}
	else
	{
		t = f2 + (m / n);
	}
	if (*t)
	{
		return *t;
	}
	for (int i = 2; i <= n;)
	{
		int j = n / (n / i);
		*t += F(n / i) * (j - i + 1);
		i = j + 1;
	}
	return *t;
}
int main()
{
	f1[1] = 1;
	cin >> m;
	cout << F(m) << endl;
	return 0;
}