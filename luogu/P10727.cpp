#include <bits/stdc++.h>
using namespace std;
int n, h, w, z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> h >> w;
		z = max(z, h * w);
	}
	cout << z << endl;
	return 0;
}