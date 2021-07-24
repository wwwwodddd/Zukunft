#include <bits/stdc++.h>
using namespace std;
int n, x;
long long a, b;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		a += x;
		b += x * x;
	}
	cout << n * b - a * a << endl;
	return 0;
}
