#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		int n, x;
		scanf("%d", &n);
		vector<int> c;
		c.resize(n);
		string z;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			z += char(c[x]++ + 97);
		}
		cout << z << endl;
	}
	return 0;
}