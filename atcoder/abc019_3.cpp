#include <bits/stdc++.h>
using namespace std;
int n, x;
set<int> s;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		while (x % 2 == 0)
		{
			x /= 2;
		}
		s.insert(x);
	}
	cout << s.size() << endl;
	return 0;
}
