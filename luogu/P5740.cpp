#include <bits/stdc++.h>
using namespace std;
struct T
{
	int x, y, z;
	string s;
}a[1000];
int n;
bool cmp(T a,T b)
{
	return a.x + a.y + a.z > b.x + b.y + b.z;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].s >> a[i].x >> a[i].y >> a[i].z;
	}
	stable_sort(a, a + n, cmp);
	cout << a->s << ' ' << a->x << ' ' << a->y << ' ' << a->z << endl;
	return 0;
}