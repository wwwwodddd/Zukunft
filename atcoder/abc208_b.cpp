#include <bits/stdc++.h>
using namespace std;
int n, z;
int main()
{
	cin >> n;
	for (int i = 1; n > 0; i++)
	{
		z += n % i;
		n /= i;
	}
	cout << z << endl;
	return 0;
}
