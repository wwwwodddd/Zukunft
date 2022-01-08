#include <bits/stdc++.h>
using namespace std;
string o, e;
int main()
{
	cin >> o >> e;
	for (int i = 0; i < o.size() + e.size(); i++)
	{
		if (i & 1)
		{
			cout << e[i / 2];
		}
		else
		{
			cout << o[i / 2];
		}
	}
	cout << endl;
	return 0;
}
