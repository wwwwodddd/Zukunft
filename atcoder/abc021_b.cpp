#include <bits/stdc++.h>
using namespace std;
int n, a, b, k;
int p[120];
int main()
{
	cin >> n >> a >> b >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> p[i];
	}
	p[k++] = a;
	p[k++] = b;
	sort(p, p + k);
	for (int i = 1; i < k; i++)
	{
		if (p[i - 1] == p[i])
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
