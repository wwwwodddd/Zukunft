#include <bits/stdc++.h>
using namespace std;
int n;
long long z;
vector<int> a;
int main()
{
	cin >> n;
	a.resize(1 << n);
	for (int i = 1; i < 1 << n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		int p = min_element(a.begin() + 1, a.end()) - a.begin();
		z += a[p];
		vector<int> b;
		for (int j = 0; j < a.size(); j++)
		{
			if (j < (j ^ p))
			{
				b.push_back(min(a[j], a[j ^ p]));
			}
		}
		a = b;
	}
	cout << z << endl;
	return 0;
}