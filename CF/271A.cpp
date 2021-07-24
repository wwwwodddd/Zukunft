#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	for (n++;;n++)
	{
		set<int> s;
		s.insert(n % 10);
		s.insert(n / 10 % 10);
		s.insert(n / 100 % 10);
		s.insert(n / 1000);
		if (s.size() == 4)
		{
			break;
		}
	}
	cout << n << endl;
	return 0;
}
