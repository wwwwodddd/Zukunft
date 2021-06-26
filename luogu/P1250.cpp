#include <bits/stdc++.h>
using namespace std;
int n, m, z;
int b[30020];
int e[30020];
int t[30020];
int v[30020];
int o[30020];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> b[i] >> e[i] >> t[i];
		o[i] = i;
	}
	sort(o, o + m, [](int x, int y) { return e[x] < e[y]; });
	for (int i = 0; i < m; i++)
	{
		for (int j = e[o[i]]; j >= b[o[i]]; j--)
		{
			t[o[i]] -= v[j];
		}
		for (int j = e[o[i]]; j >= b[o[i]] && t[o[i]] > 0; j--)
		{
			if (!v[j])
			{
				v[j] = 1;
				t[o[i]]--;
				z++;
			}
		}
	}
	cout << z << endl;
	return 0;
}