#include <bits/stdc++.h>
using namespace std;
int n;
long long z, x;
int main()
{
	cin >> n >> z;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		z += abs(x);
	}
	cout << z << endl;
	return 0;
}
