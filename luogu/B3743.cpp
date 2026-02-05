#include <bits/stdc++.h>
using namespace std;
long long n;
int z;
int c[] = {1, 0, 1, 0, 0, 0, 1, 0, 2, 1};
int main()
{
	cin >> n;
	while (n > 0)
	{
		z += c[n % 10];
		n /= 10;
	}
	cout << z << endl;
	return 0;
}