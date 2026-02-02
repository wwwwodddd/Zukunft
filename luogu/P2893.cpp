#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
long long gao()
{
	long long re = 0;
	priority_queue<int> q;
	for (int i : a)
	{
		q.push(i);
		q.push(i);
		re += q.top() - i;
		q.pop();
	}
	return re;
}
int main()
{
	cin >> n;
	a.resize(n);
	for (auto &i : a)
	{
		cin >> i;
	}
	long long z = gao();
	reverse(a.begin(), a.end());
	z = min(z, gao());
	cout << z << endl;
	return 0;
}
