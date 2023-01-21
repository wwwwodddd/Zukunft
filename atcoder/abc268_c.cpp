#include <bits/stdc++.h>
using namespace std;
int n;
int p[200020];
int z[200020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		z[(i - p[i] + n + 1) % n]++;
		z[(i - p[i] + n + 0) % n]++;
		z[(i - p[i] + n - 1) % n]++;
	}
	cout << *max_element(z, z + n) << endl;
	return 0;
}