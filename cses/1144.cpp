#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> t;
pair<pair<int, int>, int> a[200020];
int p[200020];
int n, q;
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p[i]);
		t.insert(make_pair(p[i], i));
	}
	for (int i = 0; i < q; i++)
	{
		char o;
		int x, y;
		scanf(" %c%d%d", &o, &x, &y);
		if (o == '!')
		{
			t.erase(make_pair(p[x], x));
			p[x] = y;
			t.insert(make_pair(p[x], x));
		}
		else
		{
			printf("%d\n", t.order_of_key(make_pair(y + 1, 0)) - t.order_of_key(make_pair(x, 0)));
		}
	}

	return 0;
}