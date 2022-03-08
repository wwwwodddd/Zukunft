#include <bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	cout << a[a[a[0]]] << endl;
	return 0;
}
