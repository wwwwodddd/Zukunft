#include <bits/stdc++.h>
using namespace std;
long long n, i;
int main()
{
	cin >> n;
	for (i = sqrt(n); n % i != 0; i--)
	{
		
	}
	cout << i + n / i - 2 << endl;
	return 0;
}
