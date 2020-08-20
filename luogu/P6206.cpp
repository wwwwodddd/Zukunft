#include <bits/stdc++.h>
using namespace std;
long long n;
int z;
int main()
{
	cin >> n;
	while (n > 1)
	{
		if (n & 1)
		{
			n = n * 3 + 1;
		}
		else
		{
			n /= 2;
		}
		z++;
	}
	cout << z << endl;
	return 0;
}