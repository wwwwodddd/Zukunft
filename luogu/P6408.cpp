#include <bits/stdc++.h>
using namespace std;
int w, x, y, z;
pair<int, int> a[5];
int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> w >> x >> y >> z;
		a[i] = make_pair(w + x + y + z, i + 1);
	}
	sort(a, a + 5);
	printf("%d %d\n", a[4].second, a[4].first);
	return 0;
}