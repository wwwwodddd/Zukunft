#include <bits/stdc++.h>
using namespace std;
int n, d, l, z;
pair<int, int> a[200020];
int main()
{
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].second >> a[i].first;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (l < a[i].second)
		{
			l = a[i].first + d - 1;
			z++;
		}
	}
	cout << z << endl;
	return 0;	
}
