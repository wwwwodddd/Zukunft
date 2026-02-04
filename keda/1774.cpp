#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
int main()
{
	cin >> n;
	a.resize(n);
	vector<int> pre(n);
	vector<int> suf(n);
	for (int &i : a)
	{
		cin >> i;
	}
	pre[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		pre[i] = max(pre[i - 1], a[i]);
	}
	suf[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		suf[i] = max(suf[i + 1], a[i]);
	}
	long long z = 0;
	for (int i = 0; i < n; i++)
	{
		z += min(pre[i], suf[i]) - a[i];
	}
	cout << z << endl;
	return 0;
}