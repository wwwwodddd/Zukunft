#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> s;
int a[200020];
int main()
{
	cin >> n;
	s.push(0);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		while (a[s.top()] >= a[i])
		{
			s.pop();
		}
		cout << s.top() << " ";
		s.push(i);
	}
	return 0;
}