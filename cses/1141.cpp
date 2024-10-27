#include <bits/stdc++.h>
using namespace std;
int n;
set<int> s;
int a[200020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int z = 0;
	for (int i = 0, j = 0; i < n;)
	{
		while (j < n && s.find(a[j]) == s.end())
		{
			s.insert(a[j]);
			j++;
		}
		z = max(z, j - i);
		s.erase(a[i++]);
	}
	cout << z << endl;
	return 0;
}